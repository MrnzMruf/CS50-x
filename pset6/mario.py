def get_int(prompt):
    while True:
        try:
            # Get input from user
            height = int(input(prompt))
            # Check if the height is between 1 and 8
            if 1 <= height <= 8:
                return height
            else:
                print("Please enter a positive integer between 1 and 8.")
        except ValueError:
            print("Invalid input. Please enter a positive integer between 1 and 8.")

def main():
    # Prompt the user for the height of the pyramid
    height = get_int("Enter the height of the half-pyramid (1-8): ")

    # Generate the half-pyramid
    for i in range(1, height + 1):
        # Print the spaces for left alignment
        print(" " * (height - i), end="")
        # Print the left side of the pyramid
        print("#" * i, end="  ")  # Two spaces between the pyramids
        # Print the right side of the pyramid
        print("#" * i)

if __name__ == "__main__":
    main()  
