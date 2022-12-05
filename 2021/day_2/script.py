#get data
with open("inp.in", "r") as f:
    data = [x.strip("\n") for x in f.readlines()]


# Calculate the horizontal position and depth you would have after following the planned course.
# What do you get if you multiply your final horizontal position by your final depth?

# PART 2
# adding aim

x = 0
depth = 0
aim = 0

for elem in data:
    keyword = elem.split()[0]
    n = int(elem.split()[1])

    if keyword == "forward":
        x += n
        depth += aim * n
    
    elif keyword == "down":
        aim += n
        # depth += n
    
    elif keyword == "up":
        # depth -= n
        aim -= n

print(f"x pos: {x}; depth: {depth}")
print(x * depth)


