# 累積分布関数の逆関数（簡易版）
function <- inv_cdf( pdf, cum ){
  cdf <- cumsum( pdf )
  ind <- which ( cum - cdf <= 0 )[ 1 ]
  return( ind )
}
