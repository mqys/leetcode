class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C - A) * (D - B), s2 = (G - E) * (H - F), width, height;
        // no cover
        if (E >= C || G <= A || F >= D || H <= B) return s1 + s2;
        // has cover
        if (E >= A) 
            width = G > C ? C - E : G - E;
        else
            width = G < C ? G - A : C - A;
        if (F >= B) 
            height = H > D ? D - F : H - F;
        else
            height = H < D ? H - B : D - B;
        return s1 + s2 - width * height;
    }
};