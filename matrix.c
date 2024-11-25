#include "matrix.h"
// #include "quantum.h"

// Define row and column pins
//
// "cols": ["GP27", "GP26", "GP22", "GP20", "GP23", "GP21"],
// "rows": ["GP5", "GP6", "GP7", "GP8", "GP9"]
static const pin_t row_pins[MATRIX_ROWS] = { GP5, GP6, GP7, GP8, GP9 };
static const pin_t col_pins[MATRIX_COLS] = { GP27, GP26, GP22, GP20, GP23, GP21 };

// Define which pins should be inverted (adjust as needed)
static const bool inverted_pins[MATRIX_ROWS + MATRIX_COLS] = {
    false, false, false, false, false,  // Rows
    true , true, false, false, false, false    // Columns
};

// Matrix state
matrix_row_t matrix[MATRIX_ROWS];

// Helper functions
static void set_pin_inverted_high(pin_t pin, bool is_inverted) {
    if (is_inverted) {
        writePinLow(pin); // Inverted HIGH = LOW
    } else {
        writePinHigh(pin); // Normal HIGH
    }
}

static void set_pin_inverted_low(pin_t pin, bool is_inverted) {
    if (is_inverted) {
        writePinHigh(pin); // Inverted LOW = HIGH
    } else {
        writePinLow(pin); // Normal LOW
    }
}

static bool read_pin_inverted(pin_t pin, bool is_inverted) {
    bool state = readPin(pin);
    return is_inverted ? !state : state; // Invert if necessary
}

// Initialize the matrix
void matrix_init(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        setPinInputHigh(row_pins[row]); // Enable pull-up
    }

    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        setPinOutput(col_pins[col]);
        set_pin_inverted_low(col_pins[col], inverted_pins[MATRIX_ROWS + col]); // Disable columns
    }
}

// Scan the matrix
uint8_t matrix_scan(void) {
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        // Enable the column
        set_pin_inverted_high(col_pins[col], inverted_pins[MATRIX_ROWS + col]);

        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            // Read the row state and store it in the matrix
            bool key_state = read_pin_inverted(row_pins[row], inverted_pins[row]);
            if (key_state) {
                matrix[row] |= (1 << col); // Set the bit
            } else {
                matrix[row] &= ~(1 << col); // Clear the bit
            }
        }

        // Disable the column
        set_pin_inverted_low(col_pins[col], inverted_pins[MATRIX_ROWS + col]);
    }

    return 1; // Return non-zero to indicate the matrix state has changed
}

// Get a row from the matrix
matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}
