def get_credit_card_number():
    """
    Prompts the user for a credit card number and returns it as a string.
    Assumes the input will be numeric as per the problem statement.
    """
    return input("Enter credit card number: ")

def validate_credit_card(number):
    """
    Validates the credit card number using the Luhn algorithm.
    Also checks the card type based on the number.
    Returns card type as a string: "AMEX", "MASTERCARD", "VISA", or "INVALID".
    """

    # Luhn Algorithm to validate the credit card number
    def luhn_check(num):
        total = 0
        reverse_digits = num[::-1]

        for i, digit in enumerate(reverse_digits):
            n = int(digit)
            # Double every second digit
            if i % 2 == 1:
                n *= 2
                if n > 9:  # Subtract 9 if the result is greater than 9
                    n -= 9
            total += n

        return total % 10 == 0  # Valid if total modulo 10 is 0

    # Check if the number is valid using Luhn's algorithm
    if not luhn_check(number):
        return "INVALID"

    # Determine the card type
    length = len(number)
    if length == 15 and (number.startswith('34') or number.startswith('37')):
        return "AMEX"
    elif length == 16 and (number.startswith('51') or number.startswith('52') or number.startswith('53') or
                            number.startswith('54') or number.startswith('55')):
        return "MASTERCARD"
    elif (length == 13 or length == 16) and number.startswith('4'):
        return "VISA"

    return "INVALID"

def main():
    # Get the credit card number from the user
    credit_card_number = get_credit_card_number()
    # Validate the credit card and get the type
    card_type = validate_credit_card(credit_card_number)
    print(card_type)

if __name__ == "__main__":
    main()
