int firstBadVersion(int n) {
    int low = 1, high = n, mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(isBadVersion(mid)) {
            if(!isBadVersion(mid - 1))
                return mid;
            high = mid - 1;
        }
        else if(!isBadVersion(mid))
            low = mid + 1;
    }
    return -1;
}