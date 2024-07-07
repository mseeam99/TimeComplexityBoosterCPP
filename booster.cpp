static const bool Booster = [](){
    #pragma GCC optimize("OFast")
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();




int init = [] {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ofstream out("user.out");
    for (string str; getline(std::cin, str); out << "\n") {
        if (str.size() <= 2) {
            out << 0;
            continue;
        }
        int lastSeenPos[256] = {0};
        int res = 1;
        int l = 1;
        int r = 1;
        while (r < str.size() - 1) {
            if (lastSeenPos[str[r]] >= l) {
                res = max(res, r - l);
                l = lastSeenPos[str[r]] + 1;
            }
            lastSeenPos[str[r]] = r;
            ++r;
        }
        res = max(res, r - l);
        out << res;
    }
    out.flush();
    exit(0);
    return 0;
}();







