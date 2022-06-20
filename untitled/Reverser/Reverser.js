function reverse32(num) {
    var temp = ((num << 8) & 0xff00ff00) | ((num >> 8) & 0xff00ff);
    return (temp << 16) | (temp >> 16);
}