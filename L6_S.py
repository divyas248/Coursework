import random

def numbering(in_filename, out_filename):
    '''

    '''
    # Number the lines in the file, including a colon
    file1 = open(in_filename, 'r')
    file2 = open(out_filename, 'w')
    i = 1
    line = file1.readline()
    while line != '':
        file2.write(str(i) + ':' + line)
        i += 1
        line = file1.readline()
    file1.close()
    file2.close()


def scramble(in_filename, out_filename):
    '''

    '''
    # Create a list with elements from the file lines, and shuffle the list
    # List length = # of lines in file 
    file1 = open(in_filename, 'r')
    count = 0
    array = []
    for line in file1:
        array.append(str(count + 1))
        count += 1
    random.shuffle(array)
    file1.close()

    # Checks to see if the line header is equal to the array index
    # If they match, it writes the line into the file
    file2 = open(out_filename, 'w')
    for i in range(len(array)):
        file1 = open(in_filename, 'r')
        for line in file1:
            if line.split(':')[0] == array[i] and i != len(array) - 1:
                file2.write(line[:])
            elif line.split(':')[0] == array[i] and i == len(array) - 1:
                file2.write(line[:].rstrip())
        file1.close()
    file2.close()


if __name__ == "__main__":
    numbering('test_s_input.txt', 's_input.txt')
    scramble('s_input.txt', 's_input2.txt')
