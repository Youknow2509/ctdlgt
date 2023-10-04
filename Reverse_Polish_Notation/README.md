# Qui tắc chuyển đổi từ biểu thức trung tố sang biểu thức Ba Lan:

- Dùng một **stack** lưu các toán hạng: `st`.
- Dùng một **string** lưu kết quả chuyển đổi: `rpn`.
- Duyệt từng phần tử từ trái qua phải:
    + Nếu gặp toán hạng thì thêm nó vào `rpn`.
    + Nếu không phải:
        + Ngăn xếp trống thì thêm vào `st`.
        + Nếu toán tử đầu trên cùng `st` có độ ưu tiên >= toán tử hiện tại 
            +   B1:  Lấy lần lượt các toán tử trong `st` ra, thêm lần lượt vào `rpn` đến khi phần tử trên cùng `st` có độ ưu tiên thấp hơn.
            + B2:   Đẩy toán tử hiện tại vào `st`.
        + Nếu là `')'` thì cũng lần luợt lấy các toán tử trong `st` ra, thêm lần lượt vào `rpn` đến khi đến phần tử `'('` thì dừng, sau đó xoá phần tử `'('`.

- Mức độ ưu tiên:
    - 1: `^`
    - 2: `*`, `/`
    - 3: `+`, `-`