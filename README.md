# Library Management System

Welcome to the **Library Management System** built in C++. This system is designed to manage library operations such as registering members, adding and lending books, and searching for both books and members. It provides a console-based interface for users to interact with the library's functionality.

## Features

- **User Registration**: Users can register by providing personal details such as name, last name, student number, and national number.
- **User Login**: Registered users can log in to the system using their name and student number.
- **Book Management**: Admin can add books by entering details such as book name, author, publication year, and barcode.
- **Book Search**: Users can search for books by name, author, or barcode.
- **Lend Books**: Users can borrow books, and the system keeps track of the lending date and the expected return date.
- **Member Search**: Admin can search for registered members by name.
- **Edit Book Details**: Admin can edit the details of any book by its barcode.
- **Track Lending**: Admin can view lending history by date to track which books were lent or returned on specific days.

## File Structure

- **members.dat**: Stores member details such as name, student number, and national number.
- **books.dat**: Stores book details including book name, author, publication year, barcode, and availability.
- **Lend Books.dat**: Tracks books that have been lent out along with the borrower's student number and lending/return dates.
- **Temp.dat**: Temporary file used for updating book information (e.g., during edits).

## Setup

1. Clone the repository:

   ```bash
   git clone https://github.com/kasrababazadeh/-library-management-system.git
   '''

### Setup Instructions

1. Open the project in your preferred C++ IDE or compiler.
   
2. Make sure to update the file paths for `members.dat`, `books.dat`, `Lend Books.dat`, and `Temp.dat` in the code to match your local environment.
   
3. Compile and run the project.


### Usage

1. Upon running the program, you will be presented with the option to either **Login** or **Register** as a new member.
   
2. After logging in, you can access the library's main features:

   - **Add a Book**: Allows adding a new book with details such as the name, author, publication year, and barcode.
   
   - **Search Book**: Search for books by name, author, or barcode.
   
   - **Lend a Book**: Borrow a book from the library and set the lending period.
   
   - **Edit Book**: Modify the details of an existing book by providing its barcode.
   
   - **Search Member**: Look up members by their name.
   
   - **View Lend and Return History**: View the list of books lent or due for return on specific dates.


### Future Enhancements

- Improve the user interface and error handling.
- Add password-based login for members.
- Implement a role-based system (e.g., admin vs. member).
- Add a GUI interface for better user experience.


### Contributing

Contributions are welcome! Please fork this repository, create a new branch, and submit a pull request.


## License

This project is licensed under the MIT License. For more details, refer to the [LICENSE](./LICENSE) file in the repository.


## Contact

If you have any questions or run into issues, feel free to reach out at:

**Email**: [kasra.babazadeh@gmail.com](mailto:kasra.babazadeh@gmail.com)

