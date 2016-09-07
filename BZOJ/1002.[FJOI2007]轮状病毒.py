f = [0 for i in range(0, 101)]
f[1] = 1
f[2] = 5
for i in range(3, 101):
    f[i] = 3 * f[i-1] + 2 - f[i-2]
n = int(input())
print (f[n])
