// main.cpp
#include <iostream>
#include <limits>  // For std::numeric_limits
#include "OurQueue.h"

/**
 * @brief Main function to interact with a queue.
 * 
 * This function provides a simple menu for the user to interact with the
 * `OurQueue` class, offering options like enqueue, dequeue, peek, and print.
 * 
 * The program continues to run until the user selects the exit option.
 * 
 * @return 0 on successful completion.
 */
int main() {
    OurQueue<int> myQueue;  /**< Queue to hold integer values */
    int choice;             /**< User's menu choice */
    int value;              /**< Value for enqueue operations */

    while (true) {
        // Display menu options
        std::cout << "Queue Operations Menu: \n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Peek Front\n";
        std::cout << "4. Clear Queue\n";
        std::cout << "5. Check if Queue is Empty\n";
        std::cout << "6. Print Queue\n";
        std::cout << "7. Exit\n";

        // Ask user for a choice
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Handle invalid input
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 7.\n";
            continue; // Ask the user for input again
        }

        // Process the choice
        switch (choice) {
            case 1: // Enqueue
                std::cout << "Enter value to enqueue: ";
                std::cin >> value;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid value. Please enter a valid number.\n";
                } else {
                    myQueue.enqueue(value);
                    std::cout << value << " has been enqueued.\n";
                }
                break;

            case 2: // Dequeue
                if (myQueue.dequeue()) {
                    std::cout << "Front item dequeued.\n";
                } else {
                    std::cout << "Queue is empty. Cannot dequeue.\n";
                }
                break;

            case 3: // Peek Front
                try {
                    int frontItem = myQueue.peekFront();
                    std::cout << "Front item is: " << frontItem << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;

            case 4: // Clear Queue
                myQueue.clear();
                std::cout << "Queue has been cleared.\n";
                break;

            case 5: // Check if Empty
                if (myQueue.isEmpty()) {
                    std::cout << "Queue is empty.\n";
                } else {
                    std::cout << "Queue is not empty.\n";
                }
                break;

            case 6: // Print Queue
                myQueue.printQueue();  // Print all the items in the queue
                break;

            case 7: // Exit
                std::cout << "Exiting program.\n";
                return 0;

            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }
    }

    return 0;
}
