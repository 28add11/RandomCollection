total = 0
upto = 100000
i = 1
otp = i * i
while otp < upto:
    i += 1
    otp = i * i
    if otp % 392 == 0:
        total += 1
print(total)