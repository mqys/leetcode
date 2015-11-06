class Solution {
public:
    int compareVersion(string version1, string version2) {
        // the num after '.' means the xth time revision of the current version
        // may have more one '.'
        int pos1 = 0, pos2 = 0;
        while (pos1 != string::npos || pos2 != string::npos) {
            auto dot1 = version1.find('.', pos1), dot2 = version2.find('.', pos2); // not found . return npos
            auto count1 = (dot1 == string::npos) ? dot1 : dot1 - pos1, // last num, no . after return npos
                    count2 = (dot2 == string::npos) ? dot2 : dot2 - pos2;
            int v1 = (pos1 == string::npos) ? 0 : stoi(version1.substr(pos1, count1)),
                    v2 = (pos2 == string::npos) ? 0 : stoi(version2.substr(pos2, count2));
            if (v1 - v2 > 0) return 1;
            if (v1 - v2 < 0) return -1;
            pos1 = (dot1 == string::npos) ? string::npos : dot1 + 1;
            pos2 = (dot2 == string::npos) ? string::npos : dot2 + 1;
        }
        return 0;
    }
};