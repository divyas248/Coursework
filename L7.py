def play():
    ''' (None) -> (None)
    
        Starts a game of 2-Player Sudoku Game
    '''
    size()
    game(size) # Initializes game
    show(game)

    for i in range(size**2):
        while i%2 == 0 and True:
            l = input("Player A please enter a move: ")
            if quit_or_save(l) == False:
                return False
            else:
                row_column_move(l)
            if check_move(row, column, move) == False:
                print("You have entered an invalid move!")
            elif check_move(row, column, move) == True:
                game[row][column] = move
                show(game)
                if check_win() == 0:
                    break
                elif check_win() == 1:
                    print("Player A wins!")
                    save()
                else:
                    print("The game is tied.")
                    save()
                    
        while i%2 == 1 and True:
            l = input("Player B please enter a move: ")
            if quit_or_save(l) == False:
                return False
            else:
                row_column_move(l)
            if check_move(row, column, move) == False:
                print("You have entered an invalid move!")
            elif check_move(row, column, move) == True:
                game[row][column] = move
                show(game)
                if check_win() == 0:
                    break
                elif check_win() == 1:
                    print("Player B wins!")
                    save()
                else:
                    print("The game is tied.")
                    save()
                    
def quit_or_save(l):
    ''' (str) -> boolean

        Checks if l is equal to 'q' or 's'
        Quits or saves respectively, and returns False
    '''
    if l == 'q':
        return False
    elif l == 's':
        save()
        return False
    
def row_column_move(l):
    ''' (str) -> int, int, int

        Globalizes row, column and move as values
    '''
    l = l.split(', ')
    global row
    global column
    global move
    row, column, move = int(l[0]), int(l[1]), int(l[2])
                    
def size():
    ''' (None) -> int

        Asks for the grid size (either 4, 9 or 16)
        Will continue to ask if not one of the three options
        Returns size
    '''
    while True:
        global size
        size = int(input("Please enter a grid size: "))
        if size == 4 or size == 9 or size == 16:
            return size
        else:
               print("You have entered an invalid size. Please try again")

def game(size):
    ''' (int) -> list
        
        Returns game (a matrix of zeros of size x size)
    '''
    global game
    game = []
    for i in range(size):
        game.append([])
        for j in range(size):
            game[i].append(0)
    return game

def show(game):
    ''' (list) -> (None)

        Prints the matrix game in sudoku format
    '''
    for i in range(len(game)):
        if i%size**(1/2) == 0 and i != 0:
                print('-' * size * 2)
        for j in range(len(game)):
            if j%size**(1/2) == 0 and j != 0:
                print('|', end = '')
            print(game[i][j], end = '')
            if game[i][j] > 9 and j != len(game) - 1:
                print('', end = '')
            elif j%size**(1/2) != size**(1/2) - 1:
                print(' ', end = '')
            elif j == len(game) - 1:
                print('')

def check_move(row, column, move):
    ''' (int, int, int) -> boolean

        Checks the row and column of the inputted move to see if the same move
        exists. If it does, return False
        Calls separate functions to check the boxes
    '''
    if row > size - 1 or column > size - 1 or move > size:
        return False # Checks input
    
    elif game[row][column] != 0:
        return False # Checks if a move exists there already
    
    for j in range(size):
        if game[row][j] == move or game[j][column] == move:
            return False # Check row and column of designated square

    # Checks boxes on intervals relating to the square root of the size
    # eg. for 9x9, check 0-2, 3-5, 6-8 (indexes)
    r = int(size**(1/2)) 
    for i in range(r):
        for j in range(r):
            if row < r * (i + 1) and column < r * (j + 1):
                for k in range((r * i), r * (i + 1)):
                    for l in range((r * j), r * (j + 1)):
                        if game[k][l] == move:
                            return False 
                return True

def check_win():
    ''' (None) -> int

        Checks if a player has won
        Returns 0 if a valid move exists
        Returns 1 if the game is not full, but a valid move does not exist
        Returns 2 if the game is full
    '''
    for i in range(len(game)):
        for j in range(len(game)):
            for k in range(len(game)):
                if game[i][j] == 0:
                    if check_move(i, j, k) == True:
                        return 0
    count = 0
    for i in range(len(game)):
        for j in range(len(game)):
            if game[i][j] != 0:
                count += 1
                
    if count == size**2: # Checks if grid is full
        return 2
    else:
        return 1

def save():
    ''' () -> file

        Saves the game matrix into a designated file
        Will create the text file if it does not exist in location
    '''
    place = input("Please input the name of the file where the " +
                  "game should be saved: ")
    file = open(place + '.txt', 'w')
    s = ''
    for i in range(len(game)):
        if i%size**(1/2) == 0 and i != 0:
                s += ('-' * size * 2 + '\n')
        for j in range(len(game)):
            if j%size**(1/2) == 0 and j != 0:
                s += ('|')
            s += str(game[i][j])
            if game[i][j] > 9 and j != len(game) - 1:
                s += ('')
            elif j%size**(1/2) != size**(1/2) - 1:
                s += (' ')
            elif j == len(game) - 1:
                s += ('\n')
    file.write(s)
    file.close()

if __name__ == "__main__":
    play()
