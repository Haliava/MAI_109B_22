import argparse
import os
import sys

def script_usage():
    print("Script prolongs files with chosen suffix until chosen length by concatenation of necessary amount of chosen_file copies.")
    print("Usage: python3 file_prolonger.py [suffix] [length] [chosen_file.extension]")
    sys.exit(1)

def check_arguments(arguments_string):
    if len(arguments_string) < 1 or len(arguments_string) > 3:
        print("Error! Number of input arguments is incorrect.")
        print("Input between [1, 3] arguments. (Use '?' to understand the script mechanism.)")
        sys.exit(1)

def concatenation(suffix, length, chosen_file):
    for receiver in os.listdir():       
        if receiver.endswith(suffix):
            filesize = os.stat(receiver).st_size 
            remaining_length = length - filesize
            if remaining_length <= 0:
                continue
            with open(chosen_file, 'r') as chosen_file_object:
                with open(receiver, 'a') as receiver_object:
                    chars_to_append = chosen_file_object.read(remaining_length)
                    receiver_object.write(chars_to_append)

def file_prolonger(arguments_string):
    for argument in arguments_string:
        if argument == '?':
            script_usage()

    check_arguments(arguments_string)

    concatenation(*arguments_string)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("suffix", help="chosen file suffix")
    parser.add_argument("length", type=int, help="chosen file length (integer value)")
    parser.add_argument("chosen_file", help="chosen sourcefile.extension")
    arguments_string = parser.parse_args()

    file_prolonger([arguments_string.suffix, arguments_string.length, arguments_string.chosen_file])
    def check_arguments(arguments_string)
    
if __name__ == '__main__':
    main()
