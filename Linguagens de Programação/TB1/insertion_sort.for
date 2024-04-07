program main
    implicit none
    integer ::arr(10) = [12, 11, 13, 5, 6, 1, 25, 72, 40, 21]
    integer::n = size(arr)
    integer::i = 0
    integer::j = 0
    integer::k = 0
    
   write(*, "('Unsorted: ', 10(I2, X))") (arr(i), i = 1, n)

    do i = 2, n
        k = arr(i)
        j = i - 1

        do while (j >= 1 .and. arr(j) > k)
            arr(j + 1) = arr(j)
            j = j - 1
        end do
        arr(j + 1) = k
    end do

    write(*, "('Sorted: ', 10(I2, X))") (arr(i), i = 1, n)

end program main
