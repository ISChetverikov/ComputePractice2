#include <limits>
#include "../LW3/Matrix.h"
  
static class PCA {

    struct NipalsResult {
        Matrix<double> DataMatrix;
        Matrix<double> ScoresMatrix;
        Matrix<double> LoadingsMatrix;
        Matrix<double> RemaindersMatrix;
    };
    
public:
    
    static Matrix<double> Center(Matrix<double> matrix)
    {
        Matrix<double> result(matrix);

        int m = matrix.GetM();
        int n = matrix.GetN();

        vector<double> meanVector(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                meanVector[i] += matrix[j][i];
            meanVector[i] /= m;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                result[j][i] -= meanVector[i];

        return result;
    };

    static Matrix<double> Scale(Matrix<double> matrix)
    {
        Matrix<double> result(matrix);

        int m = matrix.GetM();
        int n = matrix.GetN();

        vector<double> devVector(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                devVector[i] += pow(matrix[j][i], 2);

            devVector[i] /= (m - 1);
            devVector[i] = sqrt(devVector[i]);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                result[j][i] /= devVector[i];

        return result;
    };

    static NipalsResult DoNipalsRoutine(Matrix<double> matrix, int pcCount)
    {
        NipalsResult nipalsResult;

        Matrix<double> D(Scale(Center(matrix)));
        int m = matrix.GetM();
        int n = matrix.GetN();
        int k = pcCount;

        Matrix<double> E(D);
        Matrix<double> T(m, k, false);
        Matrix<double> P(k, n, false);
        Matrix<double> d(m, 1, false);
        Matrix<double> p(n, 1, false);

        for (int i = 0; i < k; i++) {
            Matrix<double> t(E.SubMatrix(0, i, m, 1));

            do {
                p = (t.Transpose()*E) * (1 / (t.Transpose()*t)[0][0]);
                p = p.Transpose();
                p = p * (1 / p.Norm());

                Matrix<double> tCopy(t);
                t = (E*p) * (1 / (p.Transpose()*p)[0][0]);
                d = tCopy - t;
            } 
            while (d.Norm() > 10e-8);

            E = E - t * p.Transpose();

            for (int j = 0; j < n; j++)
            {
                P[i][j] = p[j][0];
            }
            for (int j = 0; j < m; j++)
            {
                T[j][i] = t[j][0];
            }
        }

        nipalsResult.DataMatrix = matrix;
        nipalsResult.ScoresMatrix = T;
        nipalsResult.LoadingsMatrix = P;
        nipalsResult.RemaindersMatrix = E;

        return nipalsResult;
    }

    static vector<double> GetLeverage(NipalsResult nipalsResult, int pcCount) {
        
        Matrix<double> E = nipalsResult.RemaindersMatrix;

        vector<double> leverageVector;

        int m = E.GetM();
        for (int i = 0; i < m; i++) {
            Matrix<double> t(E.SubMatrix(0, i, m, 1));
            leverageVector.push_back(
                    (t.Transpose() *
                (E.Transpose()*E).ReverseMatrix() *
                    t)[0][0]
            );
        }

        return leverageVector;
    }

    static vector<double> GetDeviation(NipalsResult nipalsResult, int pcCount) {

        Matrix<double> T = nipalsResult.ScoresMatrix;

        int m = T.GetM();
        int n = T.GetN();

        vector<double> deviationVector(m);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                deviationVector[i] = T[i][j] * T[i][j];
        
        return deviationVector;
    }


    static double GetTRVC(NipalsResult nipalsResult, int pcCount) {

        Matrix<double> T = nipalsResult.ScoresMatrix;

        int m = T.GetM();
        int n = T.GetN();
        double result = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                result += T[i][j] * T[i][j];

        return result / m / n;
    }

    static double GetERVC(NipalsResult nipalsResult, int pcCount) {

        Matrix<double> T = nipalsResult.ScoresMatrix;
        Matrix<double> D = nipalsResult.DataMatrix;

        double resultT = 0;
        double resultD = 0;

        for (int i = 0; i < T.GetM(); i++)
            for (int j = 0; j < T.GetN(); j++)
                resultT += T[i][j] * T[i][j];

        for (int i = 0; i < D.GetM(); i++)
            for (int j = 0; j < D.GetN(); j++)
                resultD += D[i][j] * D[i][j];

        return 1 - resultT / resultD;
    }

};