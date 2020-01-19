﻿#include"background.h"
hash_t hash_(char const* str)
{
	hash_t ret{ basis };
	while (*str) {
		ret ^= *str;
		ret *= prime;
		str++;
	}
	return ret;
}
constexpr hash_t hash_compile_time(char const* str, hash_t last_value)
{
	return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}
int PlaceToNum(const char Place[30]) {
	switch (hash_(Place)) {
    case hash_compile_time("乌鲁木齐国际机场"):
		return 1;
	case hash_compile_time("喀什机场"):
		return 2;
	case hash_compile_time("和田机场"):
		return 3;
	case hash_compile_time("库尔勒机场"):
        return 4;
	case hash_compile_time("克拉玛依机场"):
		return 5;
	case hash_compile_time("吐鲁番交河机场"):
		return 6;
	case hash_compile_time("哈密机场"):
		return 7;
	case hash_compile_time("阿克苏温宿机场"):
		return 8;
	case hash_compile_time("库车龟兹机场"):
		return 9;
	case hash_compile_time("布尔津喀纳斯机场"):
		return 10;
	case hash_compile_time("西宁曹家堡机场"):
		return 11;
	case hash_compile_time("格尔木机场"):
		return 12;
	case hash_compile_time("玉树巴塘机场"):
		return 13;
	case hash_compile_time("海西德令哈机场"):
		return 14;
	case hash_compile_time("海西花土沟机场"):
		return 15;
	case hash_compile_time("果洛玛沁机场"):
		return 16;
	case hash_compile_time("银川河东国际机场"):
		return 17;
	case hash_compile_time("中卫沙坡头机场"):
		return 18;
	case hash_compile_time("固原六盘山机场"):
		return 19;
	case hash_compile_time("兰州中川国际机场"):
		return 20;
	case hash_compile_time("嘉峪关机场"):
		return 21;
	case hash_compile_time("敦煌机场"):
		return 22;
	case hash_compile_time("金昌金川机场"):
		return 23;
	case hash_compile_time("张掖甘州机场"):
		return 24;
	case hash_compile_time("天水麦积山机场"):
		return 25;
	case hash_compile_time("庆阳西峰机场"):
		return 26;
	case hash_compile_time("甘南夏河机场"):
		return 27;
	case hash_compile_time("西安咸阳国际机场"):
		return 28;
	case hash_compile_time("延安二十里堡机场"):
		return 29;
	case hash_compile_time("榆林榆阳机场"):
		return 30;
	case hash_compile_time("安康机场"):
		return 31;
	case hash_compile_time("汉中城固机场"):
		return 32;
	case hash_compile_time("贵阳龙洞堡国际机场"):
		return 33;
	case hash_compile_time("荔波机场"):
		return 34;
	case hash_compile_time("黎平机场"):
		return 35;
	case hash_compile_time("安顺黄果树机场"):
		return 36;
	case hash_compile_time("兴义万峰林机场"):
		return 37;
	case hash_compile_time("铜仁凤凰机场"):
		return 38;
	case hash_compile_time("遵义新舟机场"):
		return 39;
	case hash_compile_time("毕节飞雄机场"):
		return 40;
	case hash_compile_time("凯里黄平机场"):
		return 41;
	case hash_compile_time("六盘水月照机场"):
		return 42;
	case hash_compile_time("成都双流国际机场"):
		return 43;
	case hash_compile_time("绵阳南郊机场"):
		return 44;
	case hash_compile_time("西昌青山机场"):
		return 45;
	case hash_compile_time("康定机场"):
		return 46;
	case hash_compile_time("宜宾菜坝机场"):
		return 47;
	case hash_compile_time("达州河市机场"):
		return 48;
	case hash_compile_time("南充高坪机场"):
		return 49;
	case hash_compile_time("攀枝花保安营机场"):
		return 50;
	case hash_compile_time("九寨黄龙机场"):
		return 51;
	case hash_compile_time("泸州蓝田机场"):
		return 52;
	case hash_compile_time("拉萨贡嘎机场"):
		return 53;
	case hash_compile_time("林芝米林机场"):
		return 54;
	case hash_compile_time("昌都邦达机场"):
		return 55;
	case hash_compile_time("阿里昆莎机场"):
		return 56;
	case hash_compile_time("日喀则和平机场"):
		return 57;
	case hash_compile_time("昆明长水国际机场"):
		return 58;
	case hash_compile_time("丽江三义国际机场"):
		return 59;
	case hash_compile_time("迪庆香格里拉机场"):
		return 60;
	case hash_compile_time("腾冲驼峰机场"):
		return 61;
	case hash_compile_time("文山普者黑机场"):
		return 62;
	case hash_compile_time("临沧博尚机场"):
		return 63;
	case hash_compile_time("普洱思茅机场"):
		return 64;
	case hash_compile_time("保山云瑞机场"):
		return 65;
	case hash_compile_time("芒市机场"):
		return 66;
	case hash_compile_time("昭通机场"):
		return 67;
	case hash_compile_time("重庆江北国际机场"):
		return 68;
	case hash_compile_time("万州五桥机场"):
		return 69;
	case hash_compile_time("黔江武陵山机场"):
		return 70;
	case hash_compile_time("三亚凤凰国际机场"):
		return 71;
	case hash_compile_time("海口美兰国际机场"):
		return 72;
	case hash_compile_time("琼海博鳌机场"):
		return 73;
	case hash_compile_time("三沙永兴机场"):
		return 74;
	case hash_compile_time("广州白云国际机场"):
		return 75;
	case hash_compile_time("深圳宝安国际机场"):
		return 76;
	case hash_compile_time("珠海金湾机场"):
		return 77;
	case hash_compile_time("揭阳潮汕国际机场"):
		return 78;
	case hash_compile_time("佛山沙堤机场"):
		return 79;
	case hash_compile_time("湛江机场"):
		return 80;
	case hash_compile_time("梅县长岗岌机场"):
		return 81;
	case hash_compile_time("惠州平潭机场"):
		return 82;
	case hash_compile_time("南宁吴圩国际机场"):
		return 83;
	case hash_compile_time("桂林两江国际机场"):
		return 84;
	case hash_compile_time("北海福成机场"):
		return 85;
	case hash_compile_time("柳州白莲机场"):
		return 86;
	case hash_compile_time("百色巴马机场"):
		return 87;
	case hash_compile_time("梧州长洲岛机场"):
		return 88;
	case hash_compile_time("河池金城江机场"):
		return 89;
	case hash_compile_time("长沙黄花国际机场"):
		return 90;
	case hash_compile_time("张家界荷花机场"):
		return 91;
	case hash_compile_time("怀化芷江机场"):
		return 92;
	case hash_compile_time("永州零陵机场"):
		return 93;
	case hash_compile_time("常德桃花源机场"):
		return 94;
	case hash_compile_time("衡阳南岳机场"):
		return 95;
	case hash_compile_time("邵阳武冈机场"):
		return 96;
	case hash_compile_time("武汉天河国际机场"):
		return 97;
	case hash_compile_time("宜昌三峡机场"):
		return 98;
	case hash_compile_time("襄阳刘集机场"):
		return 99;
	case hash_compile_time("恩施许家坪机场"):
		return 100;
	case hash_compile_time("神农架红坪机场"):
		return 101;
	case hash_compile_time("十堰武当山机场"):
		return 102;
	case hash_compile_time("郑州新郑国际机场"):
		return 103;
	case hash_compile_time("南阳姜营机场"):
		return 104;
	case hash_compile_time("洛阳北郊机场"):
		return 105;
	case hash_compile_time("南昌昌北国际机场"):
		return 106;
	case hash_compile_time("赣州黄金机场"):
		return 107;
	case hash_compile_time("景德镇罗家机场"):
		return 108;
	case hash_compile_time("井冈山机场"):
		return 109;
	case hash_compile_time("宜春明月山机场"):
		return 110;
	case hash_compile_time("上饶三清山机场"):
		return 111;
	case hash_compile_time("青岛流亭国际机场"):
		return 112;
	case hash_compile_time("济南遥墙国际机场"):
		return 113;
	case hash_compile_time("烟台蓬莱国际机场"):
		return 114;
	case hash_compile_time("威海大水泊机场"):
		return 115;
	case hash_compile_time("潍坊机场"):
		return 116;
	case hash_compile_time("临沂沭埠岭机场"):
		return 117;
	case hash_compile_time("东营胜利机场"):
		return 118;
	case hash_compile_time("济宁曲阜机场"):
		return 119;
	case hash_compile_time("日照山字河机场"):
		return 120;
	case hash_compile_time("厦门高崎国际机场"):
		return 121;
	case hash_compile_time("福州长乐国际机场"):
		return 122;
	case hash_compile_time("武夷山机场"):
		return 123;
	case hash_compile_time("泉州晋江国际机场"):
		return 124;
	case hash_compile_time("连城冠豸山机场"):
		return 125;
	case hash_compile_time("三明沙县机场"):
		return 126;
	case hash_compile_time("合肥新桥国际机场"):
		return 127;
	case hash_compile_time("黄山屯溪国际机场"):
		return 128;
	case hash_compile_time("安庆天柱山机场"):
		return 129;
	case hash_compile_time("阜阳西关机场"):
		return 130;
	case hash_compile_time("池州九华山机场"):
		return 131;
	case hash_compile_time("杭州萧山国际机场"):
		return 132;
	case hash_compile_time("宁波栎社国际机场"):
		return 133;
	case hash_compile_time("温州龙湾国际机场"):
		return 134;
	case hash_compile_time("台州路桥机场"):
		return 135;
	case hash_compile_time("舟山普陀山机场"):
		return 136;
	case hash_compile_time("义乌机场"):
		return 137;
	case hash_compile_time("衢州机场"):
		return 138;
	case hash_compile_time("南京禄口国际机场"):
		return 139;
	case hash_compile_time("常州奔牛国际机场"):
		return 140;
	case hash_compile_time("南通兴东国际机场"):
		return 141;
	case hash_compile_time("连云港白塔埠机场"):
		return 142;
	case hash_compile_time("徐州观音国际机场"):
		return 143;
	case hash_compile_time("盐城南洋机场"):
		return 144;
	case hash_compile_time("无锡硕放机场"):
		return 145;
	case hash_compile_time("淮安涟水机场"):
		return 146;
	case hash_compile_time("扬州泰州国际机场"):
		return 147;
	case hash_compile_time("上海浦东国际机场"):
		return 148;
	case hash_compile_time("上海虹桥国际机场"):
		return 149;
	case hash_compile_time("哈尔滨太平国际机场"):
		return 150;
	case hash_compile_time("鸡西兴凯湖机场"):
		return 151;
	case hash_compile_time("伊春林都机场"):
		return 152;
	case hash_compile_time("大庆萨尔图机场"):
		return 153;
	case hash_compile_time("漠河古莲机场"):
		return 154;
	case hash_compile_time("佳木斯东郊机场"):
		return 155;
	case hash_compile_time("牡丹江海浪机场"):
		return 156;
	case hash_compile_time("齐齐哈尔三家子机场"):
		return 157;
	case hash_compile_time("黑河瑷珲机场"):
		return 158;
	case hash_compile_time("加格达奇机场"):
		return 159;
	case hash_compile_time("长春龙嘉国际机场"):
		return 160;
	case hash_compile_time("白山长白山机场"):
		return 161;
	case hash_compile_time("延吉朝阳川机场"):
		return 162;
	case hash_compile_time("通化三源浦机场"):
		return 163;
	case hash_compile_time("白城长安机场"):
		return 164;
	case hash_compile_time("大连周水子国际机场"):
		return 165;
	case hash_compile_time("沈阳桃仙国际机场"):
		return 166;
	case hash_compile_time("朝阳机场"):
		return 167;
	case hash_compile_time("丹东浪头机场"):
		return 168;
	case hash_compile_time("锦州锦州湾机场"):
		return 169;
	case hash_compile_time("鞍山腾鳌机场"):
		return 170;
	case hash_compile_time("长海大长山岛机场"):
		return 171;
	case hash_compile_time("营口兰旗机场"):
		return 172;
    case hash_compile_time("呼和浩特白塔机场"):
		return 173;
	case hash_compile_time("通辽机场"):
		return 174;
	case hash_compile_time("包头二里半机场"):
		return 175;
	case hash_compile_time("呼伦贝尔海拉尔机场"):
		return 176;
	case hash_compile_time("赤峰玉龙机场"):
		return 177;
    case hash_compile_time("鄂尔多斯国际机场"):
		return 178;
	case hash_compile_time("二连浩特赛乌素机场"):
		return 179;
	case hash_compile_time("阿尔山伊尔施机场"):
		return 180;
	case hash_compile_time("乌海机场"):
		return 181;
	case hash_compile_time("锡林浩特机场"):
		return 182;
	case hash_compile_time("太原武宿国际机场"):
		return 183;
	case hash_compile_time("运城张孝机场"):
		return 184;
	case hash_compile_time("长治王村机场"):
		return 185;
	case hash_compile_time("吕梁大武机场"):
		return 186;
	case hash_compile_time("大同云冈机场"):
		return 187;
	case hash_compile_time("忻州五台山机场"):
		return 188;
	case hash_compile_time("临汾乔李机场"):
		return 189;
	case hash_compile_time("石家庄正定国际机场"):
		return 190;
	case hash_compile_time("秦皇岛北戴河机场"):
		return 191;
	case hash_compile_time("唐山三女河机场"):
		return 192;
	case hash_compile_time("邯郸机场"):
		return 193;
	case hash_compile_time("张家口宁远机场"):
		return 194;
	case hash_compile_time("承德普宁机场"):
		return 195;
	case hash_compile_time("北京首都国际机场"):
		return 196;
	case hash_compile_time("北京南苑机场"):
		return 197;
	case hash_compile_time("天津滨海国际机场"):
		return 198;
	default:
		return 0;
	}
}
