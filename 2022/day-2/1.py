# "A": "Y", # his rock, my paper
# "B": "X", # his paper, my rock
# "C": "Z" # tie scissors

# his
# r -> a
# p -> b
# s -> c

# me
# r -> x
# p -> y
# s -> z


with open("inp.in", "r") as inputfile:
    # 0 -> opponent
    # 1 -> you
    strategydata = [x.removesuffix("\n").split(" ") for x in inputfile.readlines()]

# print(strategydata)

LOSS = {
    "A": "Z", # his rock (A), my scissors (Z)
    "B": "X", # his paper, my rock
    "C": "Y" # his scissors, my paper
}
TIE = {
    "A": "X",
    "B": "Y",
    "C": "Z"
}

POINTS = {
    "X": 1,
    "Y": 2,
    "Z": 3
}


total_score = 0
for turn in strategydata:
    # i tie
    if TIE[turn[0]] == turn[1]:
        # print("tie")
        total_score += 3 + POINTS[turn[1]]

    # i lose
    elif LOSS[turn[0]] == turn[1]:
        # print(turn, "loss")
        total_score += POINTS[turn[1]]
    
    # i win
    else:
        # print(turn, "won")
        total_score += 6 + POINTS[turn[1]]

print(total_score)