#get data
with open("inp.in", "r") as f:
    data = [int(x.strip("\n")) for x in f.readlines()]


# PART 1
# How many measurements are larger than the previous statement?

# bigger_measurements_n = 0

# for i in range(len(data)):
#     if i == 0:
#         continue

#     if data[i] > data[i - 1]:
#         bigger_measurements_n += 1

# print(bigger_measurements_n)



# PART 2
# Consider sums of a three-measurement sliding window. How many sums are larger than the previous sum?

bigger_sums = 0
for i in range(len(data)):
    try:
        sum_1 = data[i] + data[i + 1] + data[i + 2]
        sum_2 = data[i + 1] + data[i + 2] + data[i + 3]

        if sum_2 > sum_1:
            bigger_sums += 1

    except:
        pass

print(bigger_sums)