## Ford-Johnsonアルゴリズム Merge-insertionソートの説明
LさんKさんに教わった
ランダムに並んだ数列に対して以下の操作を行う
1. 隣同士ペアにする
2. ペア内部で比較して値の大きい方を表面にする (他のペアと値を比較する際はこの大きい値を使用する)
3. 隣同士のペアが作れなくなるまで 1〜2を繰り返す
4. 値の小さい方からペアを分解し 分解して出て来た値のうち小さい方を適切な位置に挿入する
5. 分解出来なくなるまで 4を繰り返す

※ 4において挿入の順番をヤコブスタール数という数列を用いて決定する事で 二分探索時の探索回数を最小化させる必要がある
https://en.wikipedia.org/wiki/Jacobsthal_number

## iteratorを使うべきか
Yさんに教えて貰った
どちらでも良い
vectorでinsertのメソッドを呼ぶと 中身はiteratorと同じくメモリ確保し直してずらしている
vectorのメソッドでもiteratorでも良いが 実装しているうちに此処はiteratorだなと気付く箇所がある

a b c d e f g h i j k
ab cd ef gh ij k
abcd efgh ij k
abcdefgh ij k
efgh abcd ij k
efgh ij abcd k
gh ef ab ij cd k
h g f e b a j i d c k 

a c e g i k b d f h j
bdfhj k  acegi
db hf j k  ca ge i
hfdb j k  geca i
geca j k  hfdb i
hfdb geca j k  i
ca db hf ge ji k
k i e f b a c d h g j 

9 2 6 8 3 1 4 5 7 0
(9) (2) (6) (8) (3) (1) (4) (5) (7) (0)
{(9)(2)} {(6)(8)} {(3)(1)} {(4)(5)} {(7)(0)}
{(2)(9)} {(6)(8)} {(1)(3)} {(4)(5)} {(0)(7)}
[{(2)(9)}{(6)(8)}] [{(1)(3)}{(4)(5)}] {(0)(7)}
[{(2)(9)}{(6)(8)}] [{(1)(3)}{(4)(5)}] {(0)(7)}

typedef std::vector<int>	t_vec
typedef std::vector<t_vec>	t_vecvec
1 4 5 3 8 6 2 9 7 0
1[1] 1[4] 1[5] 1[3] 1[8] 1[6] 1[2] 1[9] 1[7] 1[0]
2[4 1] 2[5 3] 2[8 6] 2[9 2] 2[7 0]
4[5 3 4 1] 4[9 2 8 6] 2[7 0]
8[9 2 8 6 5 3 4 1] 2[7 0]
4[5 3 4 1] 4[9 2 8 6] 2[7 0]
2[0 7] 4[1 4 3 5] 4[2 9 6 8]
2[0 7] 2[1 4 3 5] 4[2 9 6 8]

....ABCDEFGHIJKLmnopq......
....FGHIJABCDEKLmnopq...... 5
....mnopqABCDEKLFGHIJ...... 5
....mnopqABCDEFGHIJKL...... 5

....ABCDEFGHIJKLmnopq......
....ABCDEFGHIopqmnJKL...... 3
....ABCDEpqmnoFGHIJKL...... 4
....pqmnoABCDEKLFGHIJ...... 5
....mnopqABCDEFGHIJKL...... 3

....mnopqABCDEFGHIJKL......
....GHIJKLABCDEFmnopq...... 5
....BCDEFAGHIJKLmnopq...... 5
....ABCDEFGHIJKLmnopq...... 5
