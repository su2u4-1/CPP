def f(input_string: str, input_range: list[tuple[int, int]]) -> str:
    output = ""
    for s, e in input_range:
        if e == -1:
            output += input_string[max(s, 0) :]
        else:
            output += input_string[max(s, 0) : min(e + 1, len(input_string))]
    return output


inr = tuple(map(int, input().split()))
input_range: list[tuple[int, int]] = []
for i in range(0, len(inr), 2):
    if i + 1 >= len(inr):
        input_range.append((inr[-1], -1))
        break
    elif inr[i] < inr[i + 1]:
        input_range.append((inr[i], inr[i + 1]))
    else:
        input_range.append((inr[i + 1], inr[i]))
while True:
    input_string = input("input: ")
    print("output:", f(input_string, input_range))
