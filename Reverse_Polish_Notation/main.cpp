#include <bits/stdc++.h>

using namespace std;

class RPN{
    string input;
    char top_st;
public:
    RPN(string input){
        this->input = input;
    }
    bool check_toan_hang(char ch){
        return (ch == '^') || (ch == '*') || (ch == '/') || 
                (ch == '+') || (ch == '-');
    }
    int priorityCh(char ch){
        if (ch == '^'){
            return 3;
        } else if (ch == '*' || ch == '/'){
            return 2;
        } else if (ch == '+' || ch == '-'){
            return 1;
        }
        return 0;
    }
    string solve(){
        stack<char> st;
        string rpn = "";
        int n = input.length();
        for (int i = 0; i < n; i++){
            if ((input[i] - '0') >= 0 && 
                (input[i] - '0') <= 9){ 
                    rpn += input[i];
            } else if (input[i] == '('){
                st.push('(');
            } else if (input[i] == ')'){
                top_st = st.top();
                while (top_st != '(' && !st.empty()){
                    rpn += top_st;
                    st.pop();
                    top_st = st.top();
                }
                st.pop();
            } else if (check_toan_hang(input[i])){
                if (st.empty()){
                    st.push(input[i]);
                } else{
                    top_st = st.top();
                    while (priorityCh(top_st) >= priorityCh(input[i]) &&
                            !st.empty()){
                        rpn += top_st;
                        st.pop();
                        top_st = st.top();
                    }
                    st.push(input[i]);
                }
            }
        }
        while(!st.empty()){
            rpn += st.top();
            st.pop();
        }
        return rpn;
    }
};

void run(){
    string str = "3+4*2/(1-5)^2";
    cout << "Nhập vào biểu thức: ";
    /* cin.ignore();
    getline(cin, str); */
    RPN rpn(str);
    cout << "Biểu thức sau khi chuyển sang biểu thức nghịch Ba Lan: " << rpn.solve() << endl;
}

int main(){

    run();

    return 0;
}