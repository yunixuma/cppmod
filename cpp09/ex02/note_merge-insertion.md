## Ford-Johnsonアルゴリズム Merge-insertionソートの説明
blyuさんkayumiさんに教わった
ランダムに並んだ数列に対して以下の操作を行う
1. 隣同士ペアにする
2. ペア内部で比較して値の大きい方を表面にする (他のペアと値を比較する際はこの大きい値を使用する)
3. 隣同士のペアが作れなくなるまで 1〜2を繰り返す
4. 値の小さい方からペアを分解し 分解して出て来た値のうち小さい方を適切な位置に挿入する
5. 分解出来なくなるまで 4を繰り返す

※ 4において挿入の順番をヤコブスタール数という数列を用いて決定する事で 二分探索時の探索回数を最小化させる必要がある
https://en.wikipedia.org/wiki/Jacobsthal_number

## iteratorを使うべきか
kyodaさんに教えて貰った
どちらでも良い
vectorでsortのメソッドを呼ぶと 中身はiteratorと同じくメモリ確保し直してずらしている
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
