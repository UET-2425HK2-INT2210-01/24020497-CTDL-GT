CLASS Stack:
    PRIVATE:
        ARRAY a
        INTEGER size

    CONSTRUCTOR Stack():
        a ← NULL
        size ← 0

    METHOD push(value):
        CREATE newArray[size + 1]
        FOR i FROM 0 TO size - 1:
            newArray[i] ← a[i]
        END FOR
        newArray[size] ← value
        size ← size + 1
        DELETE a
        a ← newArray

    METHOD pop():
        IF size = 0 THEN RETURN  // Tránh lỗi khi pop stack rỗng
        CREATE newArray[size - 1]
        FOR i FROM 0 TO size - 2:
            newArray[i] ← a[i]
        END FOR
        size ← size - 1
        DELETE a
        a ← newArray

    METHOD print():
        FOR i FROM 0 TO size - 1:
            PRINT a[i] WITHOUT NEWLINE
        END FOR
        PRINT NEWLINE

// MAIN PROGRAM
READ t
Stack q
WHILE t > 0:
    READ s
    IF s = "push" THEN
        READ n
        q.push(n)
    ELSE IF s = "pop" THEN
        q.pop()
    END IF
    t ← t - 1
END WHILE
q.print()

