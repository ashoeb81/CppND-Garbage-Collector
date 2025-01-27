// This class defines an element that is stored
// in the garbage collection information list.
//
template <class T>
class PtrDetails
{
  public:
    // current reference count
    unsigned refcount;

    // pointer to allocated memory
    T *memPtr;

    /* isArray is true if memPtr points
       to an allocated array. It is false
       otherwise. */
    bool isArray; // true if pointing to array

    /* If memPtr is pointing to an allocated
       array, then arraySize contains its size */
    unsigned arraySize; // size of array

    // Constructor.  Here mPtr points to the allocated
    // memory. If this is an array, then size specifies
    // the size of the array.
    PtrDetails(T* m_ptr, unsigned size=0)
    {
        // Set reference count to newly allocated memory 1.
        refcount = 1;

        // Assign memPtr to address of newly allocated memory.
        memPtr = m_ptr;

        // If size > 0 then set member variable indicating
        // newly allocated memory is associated with an array.
        if (size != 0) isArray = true;
        else isArray = false;

        arraySize = size;
    }
};

// Overloading operator== allows two class objects to be compared.
// This is needed by the STL list class.
template <class T>
bool operator==(const PtrDetails<T> &ob1,
                const PtrDetails<T> &ob2)
{
    return (ob1.memPtr == ob2.memPtr);
}