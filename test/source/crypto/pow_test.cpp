//
// MIT License
//
// Copyright (c) 2017-2018 Thibault Martinez and Simon Ninon
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//

#include <gtest/gtest.h>

#include <iota/crypto/pow.hpp>

TEST(Pow, Base) {
  IOTA::Crypto::Pow   p;
  IOTA::Types::Trytes tx =
      "AEHVKLWSCKAFTRNIQEPLGRM9YWAUFHEJNLVSJGSARSSAISLKCFUBPSCFZLJDRUARIGNAUBWQJMCBVVQIYMRUNGBVEOMB"
      "ATOOHNKWEYSSVWHCHTCEGBCLDSA9MCVGZUZUCFWFYOGIMWAQFUQUHBXJBJBVIGYWBUVDVXTQFJKAQEPPXZQAWEYUVGPD"
      "ULJKHHJRFZVTTSHZMZGAFUTDZIIEBMPPMC9KOPTFFISPOGJLCDVSOAFNK9XKYIJMYMJWSULNYPDQSMDKJDBYHDUEKHZP"
      "NTPO9IIXYUSGUCUNOPUDETVKEJBFVTQDPJRJNTNMD9JACFTBP9ZJDVA9JMTBSCKCVI9CRYKXWYCTJ9STADLXOYADJPQF"
      "LXIUMRMQWZ9EZJHXAKWDEHNPTHTWYNICVYYMDWRV9TWAFDVRDHLJHPFIQPUEVDGPE9JJMHAFLYTQZOMGYGDFHKKTIQQR"
      "VXYKJZIBKZT9JNLCBYJBOBUT9WM9AYMHP9XQKHRHULDFSIPXUPGHFEIKAABDFBSZIZQAI9BARBEQ9HGFNFGCTDADQHVW"
      "RDSOSVXNVQHM9CXCCKJSVTESDUVLNQLVVCRRACINDPHWQRTTTMZNQZFCFGMSWSRZEEDKUZTQGCWKPQ9J9QCQZJAAQFPW"
      "NQOAMZDJZJNPOZSYDYLDPN9UHHRSVUUVZNAUWTKFWIMUUCZVSZGXULHPDSMOQRRVWDXV9BCMEFEEYYBDUBBVBJBALEUU"
      "HLVMANUCWPOOBKWQRSKBUJPOBYLXQBJDUCQFZOHNNIX9VIGNXOUYXAJAWEYSDXRFCGUNMOEJDYPTZGLJDXCYOIPEMOLT"
      "DPFTTI9HPMJQAFXGISORCELHNQIMXSUCKKGWFJQYWRDXZLVVJDGPKZFGVGGPJZDRAMQVIPLVYAYURYAGEPLPMJYNLAKI"
      "FOKNQYNOIEPFJKAJGGQAQLBEVLKDPSVRWGVEEPZJPESWOQIFJWQYOWIZAVOLCVYNGOHCTJKXHNNFQWDYKJOGMEEBYVRP"
      "PXSK9WMMRUGCYRPRYWOPQNRVZWGXQUMNRMVBDQ9EAZD9JLXUREDYTOCEQCDEMLZWSLCPPFGWTBBWGINGTEXOIBORVAMZ"
      "HSWGDHXGAV9AYRIAYWFZDPNZXRLJOCUDCEESLVVOUJUDZWAHBZISPCYYCEFBIZGJQN9KUHFXOK9TISVZMEHMZFPOKDRL"
      "9Z9EOTHVKPOQVPIICYXVRBCCYRDVKAWRDBFFXOBYNPRSLQXSWAQJYIZMDPSGCHKPPN9KLR9SNCSSJT9VKESRMBLKISO9"
      "ZUEMCHGCGG9JNEFHIIRJXBXXPQLBHGLIVUUXOPSRUOVIVPIQEFTNALPTIFSQRNMNSNWOBFWPHNQIHVBMXSZWLAZDCSCX"
      "BNU9BUSM9NLCFKOJ9YOV9OZZBLOELANZVOPACMLIGROLZUAVIUARFFKFMTTWBXDIZPKTXFSTAOKDHWAUEWUYKODKDMSN"
      "FFZGFXTMHCAYDUOVPHZKA99AOZYTVQWACSODLUTCXXPJZXYCBLGENVHMCEZIJHXNNSXSV9PYQIRJSVWMWOBWKJZJTUGM"
      "CNOFDMUHICSPHFDAELIIIBBQG9DWPIWAKWTEYCGGNLLKVDZSDNZGVTZDT9J9ZHFMXNYVAEVYMHBPHEGJVDFTNAOECKBU"
      "YRPLST9TCNHYXBMPDSTVEOMNLJRHEKBHQGQDD9OGVHHPXKXKCIOALFMXMWJCIJ9AU9KPTQWFIBDEK9NDQVQQIQJOQLDM"
      "9CUHJMNOTSVVHZKXVSCEUIPBMSBMQYWROAVYBSQUASH9RPUFSFCSPZNQCMEDZRAZGNHGYJVVDPARHKTBHCALKYGILUHS"
      "YZCSRSQMOEMADCYHNSVPOUCAL9BFIBHWJRSKKPCEELPGEE9IGMT9ELMVGPW9VCBEYEYMHIEH9JSE9JPFOLTPU9VENWGW"
      "PCQFTVRZJGLDDWUBUOCNFAWWVREGUZNSC9BZLEPRFNHJURMAEF9STTMU9TCQVXQN9SJMKTMAIKVOLNSZNOYGKPHBN9WL"
      "WEVNOXJ9Z9DLSQRIVJNCEADFOZJXVCOJLBCPIJMKYAVUKMETJRYQXRENSCIAGBHBTCQEAXLYXUSOBBTPYZAZEWJVAIPM"
      "9XWKI9HLAXXAPGXOJDZGBKGRTFGVIRMBWTOBUHWQHYNUBXJGCMDEVLAKHFKDZWWMYIAYZWXJTJXWTWPREDKKWOWQLSHG"
      "THXEXIWPRAQIZGWDZTAENBXYDNJEZMMQSJVNBVDVNDRA9KPYWPMMUCAINHYZUPX999999999999999999999999PACIF"
      "ICSOUND999999999999999WGXQRYD99A99999999C99999999YVXANDXRFTSL9IIKHHW9IUIXKYCPWFXSOHVJCL9AASG"
      "EEWOYUVPKXDMQCHRXZZYCGPTLVDBRJTHJBLR9AOTONJYUKXXVBWASRVAGCZOC9WDPDJBZMIEOYZQGTDZVINBDRKOZZT9"
      "JLSCMHAOVEORURJRZQCHPL99999DMXDYIPNMTSLBGARIBQGU9YMQFHODGYROALTHWJTSWBWJ9QQJLRWWDGWSKVGQVQCN"
      "YBMUUYMNGTFX9999PACIFICSOUND999999999999999KEAXVBYJE999999999L999999999999999999999999999999"
      "99999";
  EXPECT_EQ(p(tx, 14, 4), "ZDXDWUNPQEGU9VU9PXAGCHYQMMW");
}
