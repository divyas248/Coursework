def descramble(in_filename, out_filename):
    '''

    '''
    # Get length of file
    file1 = open(in_filename, 'r')
    array = []
    for line in file1:
        array.append(line[0])
    file1.close()

    # Make new list, ordered from one to length of file
    for j in range(len(array)):
        array[j] = str(j + 1)

    # Descramble
    file2 = open(out_filename, 'w')
    for i in range(len(array)):
        file1 = open(in_filename, 'r')
        for line in file1:
            if line.split(':')[0] == array[i] and i != len(array) - 1:
                file2.write(line.split(':')[1])
            elif line == '\n' and i != len(array) - 1:
                file2.write('\n')
            elif line.split(':')[0] == array[i] and i == len(array) - 1:
                file2.write(line.split(':')[1].rstrip())
        file1.close()
    file2.close()
    
if __name__ == "__main__":
    descramble('test_d_input.txt', 'new_d.txt')
