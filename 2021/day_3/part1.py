#get data
with open("inp.in", "r") as f:
    data = [x.strip("\n") for x in f.readlines()]


# Use the binary numbers in your diagnostic report to calculate the gamma rate and epsilon rate, then multiply them together.
# What is the power consumption of the submarine? (Be sure to represent your answer in decimal, not binary.)

gamma = list("000000000000")
epsilon = list("000000000000")

for bit in range(len(data[0])):
    count_0 = 0
    count_1 = 0

    for i in range(len(data)):
        if data[i][bit] == "0":
            count_0 += 1
        elif data[i][bit] == "1":
            count_1 += 1
    
    if count_1 > count_0:
        gamma[bit] = "1"
    else:
        epsilon[bit] = "1"

print(gamma)
print(epsilon)

#convert from binary to decimal
gamma = int("".join(gamma), 2)
epsilon = int("".join(epsilon), 2)

print(gamma)
print(epsilon)

print(gamma * epsilon)