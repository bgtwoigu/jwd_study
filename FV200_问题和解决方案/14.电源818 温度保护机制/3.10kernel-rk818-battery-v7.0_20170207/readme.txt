
˵���������v7.0�汾�����ƣ��޸���һЩbug���Ż��˷ŵ�Ч����

ʹ�ã�
1. ֱ�Ӳ�ȡ�ļ����ǵķ�ʽ��������������uboot��kernel��

   ����uboot������ļ�include/power/rk818_pmic.h ��ò�Ҫ��ȫ���ǣ���fg_rk818.c�õ��ļĴ������峭��ȥ�ͺ��ˣ����������������ı������⡣
  ���⣬uboot����ʱ���������仰���뱨��parent = fdt_node_offset_by_compatible(blob, g_i2c_node, "rockchip,rk818");�����g_i2c_node�Ļ��ļ�����ǰ�����ݣ���Ӱ�칦�ܡ�

2. dts���޸Ĳο�pdf�ĵ���������Ҳ���ԣ�������ȥ���ݾɵģ������ܸ���øĵ���




=============================================
�汾��Ϣ��������ݡ�

��kernel��
commit cdb3769dc33cf08773ccc2e53dfddf6139b120f2
Author: Jianhong Chen <chenjh@rock-chips.com>
Date:   Mon Jan 23 15:01:50 2017 +0800

    power: rk818/6-battery: move irq init to the last step
    
    init irq later than workqueue_struct and delayed_work to
    avoid NULL ponint
    
    Change-Id: Ie4bc006d70d0a61b548fcdce86874de44a1dad8b
    Signed-off-by: Jianhong Chen <chenjh@rock-chips.com>


��uboot��
commit 42da0bdcc3bc4caaedc7b5b2509ebb4f07671d77
Author: Jianhong Chen <chenjh@rock-chips.com>
Date:   Tue Nov 8 08:35:15 2016 +0800

    fuel_gauge: rk816/818: init virtual dsoc earlier to avoid overriding real dsoc
    
    Change-Id: Ia7fa10b9f33280868f822aa1f74ed7b1dc653b33
    Signed-off-by: Jianhong Chen <chenjh@rock-chips.com>