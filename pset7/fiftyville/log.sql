-- check the reports on the Humphrey street
SELECT * FROM crime_scene_reports WHERE year = 2023 AND month = 7 AND day = 28 AND street = 'Humphrey'; --Nothing here
-- Check the interviews of that day:
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28; -- Ruth said 10 min after take a car from parking | Eugene said about the Leggett street at ATM | Raymond heard the thief calls to a person
-- Raymond's interview, the thief plans to catch you early in the morning on July 29.
-- Check the next flights after 28 July:
SELECT * FROM flights WHERE year = 2023 AND month = 7 AND day >= 28 ORDER BY day, hour, minute;
-- Among the flights: Flight 36 was carried out on July 29, 2023 at 8:20. This flight went from the airport with ID 8 to the airport with ID 4.
-- we need to examine the passengers of Flight 36. This flight was made on the morning of July 29, which according to Raymond's interview, the thief probably used this flight.
-- Check the passengers on flight 36:
SELECT * FROM passengers WHERE flight_id = 36; -- ****
-- And check the "leggett street" transactions:
SELECT * FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';
-- check the transaction_type = 'withdraw' as Eugene said
SELECT * FROM bank_accounts WHERE account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199);
-- check with people:
SELECT * FROM people WHERE id IN (686048, 514354, 458378, 395717, 396669, 467400, 449774, 438727);
-- a compare:
SELECT * FROM passengers WHERE passport_number IN (9878712108, 7049073643, 9586786673, 1988161715, 4408372428, 8496433585, 3592750733, 5773159633);
-- Kenny is theif ...
SELECT * FROM people WHERE name = 'Kenny'; -- i need the number of kenny to find that calls
-- (826) 555-1652 >> kenny
SELECT * FROM phone_calls WHERE caller = '(826) 555-1652';
-- in 27 July the receiver is: (066) 555-9701
-- check the name by the number:
SELECT * FROM people WHERE  phone_number = '(066) 555-9701';
-- Doris is the colleages
-- the destination city:
SELECT destination_airport_id FROM flights WHERE id = 36;
-- which one:
SELECT city FROM airports WHERE id = 4;
-- NY city

