tmp = input()
cin = tmp.split()
n = int(cin[0])
k = int(cin[1])
tmp = input()
cin = tmp.split()
a = []
res = 0
two = 1
for i in range(n+1):
    num = int(cin[i])
    a.append(num)
    res += num * two
    two *= 2
ans = 0
two = 1
for i in range(n+1):
    tmp = res - a[i] * two
    if tmp % two != 0:
        continue
    tmp /= two
    if tmp > 0 and tmp <= k:
        ans += 1
    else:
        if tmp < 0 and tmp >= -k:
            ans += 1
    two *= 2
print (ans)
