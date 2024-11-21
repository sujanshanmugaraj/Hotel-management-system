
### 1. **Room Management**
   - **Features:**
     - Add new rooms and allocate them to customers.
     - Search for rooms using room IDs.
     - Update room details, such as ID, customer name, allocated date, and type (e.g., single, double, twin).
     - Delete room records by room ID.
     - View and sort room records based on IDs.
   - **Implementation:**
     - Uses a linked list (`node` structure) to manage room details.
     - Each room is represented as a node containing information such as room ID, customer name, date, and type.

### 2. **Food Management**
   - **Features:**
     - View a menu of items with names, prices, and ratings.
     - Place orders with multiple items and quantities.
     - Add new dishes to the menu (admin panel).
     - View order history, total income for the day, and the number of customers served.
   - **Implementation:**
     - Uses doubly linked lists to manage food items (`item` structure) and order history (`order_hist` structure).
     - Orders are linked with customer details and calculated total amounts.

### **Overall Design**
- The program uses a **menu-driven approach**, allowing users to choose between room and food management systems.
- **Key Data Structures:**
  - **Linked Lists** for dynamic management of room records, food items, and order history.
  - Structures (`node`, `item`, `order_hist`) for organizing related data fields.
- **Dynamic Memory Management:** Implements nodes dynamically with `new` for flexibility in adding, updating, and deleting records.

