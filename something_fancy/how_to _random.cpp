
void insert(const uint64_t &val)
{
    // overflow check
    if (top == N)
    {
        std::cout << "\nOverflow";
        return;
    }
    // if list is not sorted, insert at the last
    // otherwise place it to correct position
    if (!isSorted)
    {
        data[top] = val;
        top++;
    }
    else
    {
        uint64_t pos = 0; // Initialize the index variable
        // Going through each element and find correct position for element
        for (uint64_t i = 0; i < top - 1; i++)
        {
            // check for the correct position
            if (data[i] <= val && val <= data[i + 1])
            {
                pos = i + 1; // assign correct pos to the index var
                break;       // to get out from the loop
            }
        }
        // if all elements are smaller than the element
        if (pos == 0)
        {
            pos = top - 1;
        }
        // shift all element to make a room for new element
        for (uint64_t i = top; i > pos; i--)
        {
            data[i] = data[i - 1];
        }
        top++;           // Increment the value of top.
        data[pos] = val; // Assign the value to the correct index in the array
    }
}