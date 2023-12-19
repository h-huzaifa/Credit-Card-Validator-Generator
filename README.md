# Credit Card Validator & Generator
By Hussain Huzaifa & Burhanuddin

This CLI application is a project for Programming Fundamental course semester 1 2021, Sir Syed CASE Institute of Technology
## Introduction
This is a university semester one project developed in C++. The project is designed to validate and generate credit card numbers, providing a practical application of programming concepts learned during the first semester. The validator ensures the integrity of credit card data, while the generator can be used to create dummy data for testing purposes. This project serves as a great starting point for students interested in software development, particularly in the areas of data validation and e-commerce. 

## Methodology
The credit card number validator and generator are created using the C++ programming language. This program has the basic objective of checking the correctness of a credit card number. There are many complex and advanced algorithms to check the validity and the credibility of a credit card number, however, for this program, Luhn’s algorithm is the most suitable option.

Aside from the validator this program also has a basic credit card number generator. The program generates a credit card number using a function of random numbers (rand() and srand()). The rand() function generates random numbers and the srand() function changes the sequence of those random numbers. Every credit card number is generated uniquely with the help of the srand() function. After the number is generated Luhn’s algorithm is used to validate the number before assigning it to the user. If the number generated is invalid, the generation process restarts until the number generated is valid.

## So far This Application
1. Validate Credit / Debit Card Numbers
2. Identifies from 5 Companies the card belongs to
    1. American Express
    2. MasterCard
    3. Visa
    4. UnionPay
    5. Discover
3. Generates Credit / Debit Card Numbers from the above 5 Companies
4. Shows Previously Generated Credit / Debit Card Numbers

The .exe file in included.
