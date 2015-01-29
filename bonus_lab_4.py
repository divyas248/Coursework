def play():
    while True:
        global grid
        grid = int(input("Please enter a grid size: "))
        if grid == 4 or grid == 9 or grid == 16:
            return grid
        else:
               print("You have entered an invalid size. Please try again")
def show():
    if grid == 4:
        print(("0 0" + '|' + "0 0" + '\n') * 2 + '-' * 8 + '\n' + ("0 0" + '|' + "0 0" + '\n') * 2)
    if grid == 9:
        print(((("0 0 0" + '|') * 2 + "0 0 0 \n") * 3 + '-' * 18 + '\n') * 2 + (("0 0 0" + '|') * 2 + "0 0 0 \n") * 3)
    if grid == 16:
        print(((("0 0 0 0" + "|") * 3 + "0 0 0 0 \n") * 4 + '-' * 32 + '\n') * 3 + (("0 0 0 0" + "|") * 3 + "0 0 0 0 \n") * 4)

if __name__ == "__main__":
    play()
    show()
