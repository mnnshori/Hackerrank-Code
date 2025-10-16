if (my_data_ptr != NULL) {
    // Safe to free or use
    free(my_data_ptr);
    my_data_ptr = NULL; // Crucial step!
}
// Now you know for certain it's safe to check again
if (my_data_ptr == NULL) {
    // Safe to allocate new memory
    my_data_ptr = malloc(SIZE);
}