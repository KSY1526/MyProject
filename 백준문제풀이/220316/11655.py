inputs = input()
ans = ''

for i in inputs:
    tem = ord(i)
    if tem < 65:
        ans += i
    elif tem <= 91:
        ans += chr(65+(ord(i)+13-65)%26)
    elif tem <= 122:
        ans += chr(97+(ord(i)+13-97)%26)
print(ans)
