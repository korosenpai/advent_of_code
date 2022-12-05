#get data
with open("inp.in", "r") as f:
    data = [x.strip("\n") for x in f.readlines()]

# Use the binary numbers in your diagnostic report to calculate the oxygen generator rating and CO2 scrubber rating,
# then multiply them together.
# What is the life support rating of the submarine? (Be sure to represent your answer in decimal, not binary.)

oxygen_data = data
c02_data = data
for bit in range(len(data[0])):
    count_0_oxygen = 0
    count_1_oxygen = 0
    count_0_c02 = 0
    count_1_c02 = 0
    most_common_bit_oxygen = 0
    least_common_bit_c02 = 1

    #for oxygen rating
    for i in range(len(oxygen_data)):
        if oxygen_data[i][bit] == "0":
            count_0_oxygen += 1
        elif oxygen_data[i][bit] == "1":
            count_1_oxygen += 1
    
    if count_1_oxygen >= count_0_oxygen:
        most_common_bit_oxygen = 1

    if len(oxygen_data) > 1:
        oxygen_data = list(filter(lambda i: i[bit] == str(most_common_bit_oxygen), oxygen_data))

    #for c02 scrubber rating
    for i in range(len(c02_data)):
        if c02_data[i][bit] == "0":
            count_0_c02 += 1
        elif c02_data[i][bit] == "1":
            count_1_c02 += 1
    
    if count_0_c02 <= count_1_c02:
        least_common_bit_c02 = 0

    if len(c02_data) > 1:
        c02_data = list(filter(lambda i: i[bit] == str(least_common_bit_c02), c02_data))

#oxygen and c02 data are a list so we have to pick the first (and only) element 
oxygen_generator_rating = int(oxygen_data[0], 2)
c02_scrubber_rating = int(c02_data[0], 2)

print(oxygen_generator_rating * c02_scrubber_rating)



