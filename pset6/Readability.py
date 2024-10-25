from cs50 import get_string

def main():
    text = get_string("Text: ")

    # Initialize counters
    letters = 0
    words = 0
    sentences = 0

    # Analyze the text
    for char in text:
        if char.isalpha():
            letters += 1
        elif char.isspace():
            continue
        elif char in ".!?":
            sentences += 1

    # Words are counted by splitting the text by whitespace
    words = len(text.split())

    # Calculate the averages L and S
    L = (letters / words) * 100
    S = (sentences / words) * 100

    # Calculate the Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8

    # Determine the grade level
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")

if __name__ == "__main__":
    main()
