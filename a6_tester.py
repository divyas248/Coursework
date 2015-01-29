
import re
import filecmp

# note that importing your modules should initiate no program execution
import L6_S
import L6_D

def find_line_in_file(fname, line, index):
    line = line.rstrip("\n")
    with open(fname) as file:
        i = 0
        for ln in file:
            i += 1
            if i != index:
                continue
            ln = ln.rstrip("\n")
            if ln == line:
                return True
            return False

    return False

def test_scrambler_output(ref_name, out_name):
    out_file = open(out_name)

    for line in out_file:
        reg = re.compile("^[0-9]*:.*$")
        if reg.match(line) == None:
            print('Line "{}" does not match proper format!'.format(line))
            return False
        index = int(line[0:line.find(":")])
        line = line[line.find(":")+1:]
        if not find_line_in_file(ref_name, line, index):
            print('Line "{}" does not exists in the reference file!'
                  .format(line.strip("\n")))
            return False
    
    return True

if __name__ == "__main__":
    scramble_in_file = "test_s_input.txt"
    scramble_out_file = "test_s_output.txt"
    descramble_in_file = "test_d_input.txt"
    descramble_out_file = "test_d_output.txt"

    print("Scrambling file {} into {}...".format(scramble_in_file, 
                                                 scramble_out_file))
    L6_S.scramble(scramble_in_file , scramble_out_file )

    if test_scrambler_output(scramble_in_file, scramble_out_file):
        print("Scrambler basic test Passed!")
    else:
        print("Scrambler basic test Failed!")

    print("Descrambling file {} into {}..."
          .format(scramble_out_file, descramble_out_file))
    L6_D.descramble(descramble_in_file, descramble_out_file)

    if filecmp.cmp(scramble_in_file, descramble_out_file):
        print("Descrambler basic test Passed!")
    else:
        print("Descrambler basic test Failed!")


