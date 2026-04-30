<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.1.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Description" color="1" fill="1" visible="yes" active="yes"/>
<layer number="196" name="logo1" color="12" fill="1" visible="yes" active="yes"/>
<layer number="198" name="logo2" color="2" fill="1" visible="yes" active="yes"/>
<layer number="199" name="InfoNew" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="CANgraph_EN_WE">
<description>&lt;b&gt;ICCS SDK PLUS library&lt;/b&gt;&lt;p&gt;
General library for graphical programming of all modules.</description>
<packages>
</packages>
<symbols>
<symbol name="FRAME_WE">
<wire x1="-10.16" y1="-170.18" x2="40.64" y2="-170.18" width="0.3048" layer="94"/>
<wire x1="40.64" y1="-170.18" x2="88.265" y2="-170.18" width="0.3048" layer="94"/>
<wire x1="88.265" y1="-170.18" x2="135.89" y2="-170.18" width="0.3048" layer="94"/>
<wire x1="135.89" y1="-170.18" x2="183.515" y2="-170.18" width="0.3048" layer="94"/>
<wire x1="183.515" y1="-170.18" x2="231.14" y2="-170.18" width="0.3048" layer="94"/>
<wire x1="250.19" y1="-170.18" x2="250.19" y2="-116.205" width="0.3048" layer="94"/>
<wire x1="250.19" y1="-116.205" x2="250.19" y2="-65.405" width="0.3048" layer="94"/>
<wire x1="250.19" y1="-65.405" x2="250.19" y2="-14.605" width="0.3048" layer="94"/>
<wire x1="250.19" y1="-14.605" x2="250.19" y2="8.89" width="0.3048" layer="94"/>
<wire x1="-10.16" y1="8.89" x2="-10.16" y2="-14.605" width="0.3048" layer="94"/>
<wire x1="-10.16" y1="-14.605" x2="-10.16" y2="-65.405" width="0.3048" layer="94"/>
<wire x1="-10.16" y1="-65.405" x2="-10.16" y2="-116.205" width="0.3048" layer="94"/>
<wire x1="-10.16" y1="-116.205" x2="-10.16" y2="-170.18" width="0.3048" layer="94"/>
<wire x1="-6.985" y1="-167.005" x2="40.64" y2="-167.005" width="0.3048" layer="94"/>
<wire x1="40.64" y1="-167.005" x2="88.265" y2="-167.005" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-167.005" x2="247.015" y2="-161.925" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-161.925" x2="247.015" y2="-156.845" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-156.845" x2="247.015" y2="-151.765" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-151.765" x2="247.015" y2="-146.685" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-146.685" x2="247.015" y2="-116.205" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-116.205" x2="247.015" y2="-65.405" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-65.405" x2="247.015" y2="-14.605" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-14.605" x2="247.015" y2="5.715" width="0.3048" layer="94"/>
<wire x1="183.515" y1="5.715" x2="135.89" y2="5.715" width="0.3048" layer="94"/>
<wire x1="135.89" y1="5.715" x2="88.265" y2="5.715" width="0.3048" layer="94"/>
<wire x1="88.265" y1="5.715" x2="40.64" y2="5.715" width="0.3048" layer="94"/>
<wire x1="40.64" y1="5.715" x2="-6.985" y2="5.715" width="0.3048" layer="94"/>
<wire x1="-6.985" y1="5.715" x2="-6.985" y2="-14.605" width="0.3048" layer="94"/>
<wire x1="-6.985" y1="-14.605" x2="-6.985" y2="-65.405" width="0.3048" layer="94"/>
<wire x1="-6.985" y1="-65.405" x2="-6.985" y2="-116.205" width="0.3048" layer="94"/>
<wire x1="-6.985" y1="-116.205" x2="-6.985" y2="-167.005" width="0.3048" layer="94"/>
<wire x1="183.515" y1="8.89" x2="135.89" y2="8.89" width="0.3048" layer="94"/>
<wire x1="135.89" y1="8.89" x2="88.265" y2="8.89" width="0.3048" layer="94"/>
<wire x1="88.265" y1="8.89" x2="40.64" y2="8.89" width="0.3048" layer="94"/>
<wire x1="40.64" y1="8.89" x2="-10.16" y2="8.89" width="0.3048" layer="94"/>
<wire x1="183.515" y1="8.89" x2="183.515" y2="5.715" width="0.3048" layer="94"/>
<wire x1="183.515" y1="-167.005" x2="183.515" y2="-170.18" width="0.3048" layer="94"/>
<wire x1="-10.16" y1="-65.405" x2="-6.985" y2="-65.405" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-14.605" x2="250.19" y2="-14.605" width="0.3048" layer="94"/>
<wire x1="88.265" y1="5.715" x2="88.265" y2="8.89" width="0.3048" layer="94"/>
<wire x1="88.265" y1="-167.005" x2="88.265" y2="-170.18" width="0.3048" layer="94"/>
<wire x1="-10.16" y1="-116.205" x2="-6.985" y2="-116.205" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-65.405" x2="250.19" y2="-65.405" width="0.3048" layer="94"/>
<wire x1="-10.16" y1="-14.605" x2="-6.985" y2="-14.605" width="0.3048" layer="94"/>
<wire x1="40.64" y1="5.715" x2="40.64" y2="8.89" width="0.3048" layer="94"/>
<wire x1="247.015" y1="-116.205" x2="250.19" y2="-116.205" width="0.3048" layer="94"/>
<wire x1="135.89" y1="5.715" x2="135.89" y2="8.89" width="0.3048" layer="94"/>
<wire x1="231.14" y1="8.89" x2="231.14" y2="5.715" width="0.3048" layer="94"/>
<wire x1="231.14" y1="-167.005" x2="231.14" y2="-170.18" width="0.3048" layer="94"/>
<wire x1="135.89" y1="-167.005" x2="135.89" y2="-170.18" width="0.3048" layer="94"/>
<wire x1="40.64" y1="-170.18" x2="40.64" y2="-167.005" width="0.3048" layer="94"/>
<wire x1="146.685" y1="-167.005" x2="146.685" y2="-146.685" width="0.3048" layer="94"/>
<wire x1="146.685" y1="-146.685" x2="205.74" y2="-146.685" width="0.3048" layer="94"/>
<wire x1="205.74" y1="-146.685" x2="247.015" y2="-146.685" width="0.3048" layer="94"/>
<wire x1="236.855" y1="-167.005" x2="236.855" y2="-161.925" width="0.3048" layer="94"/>
<wire x1="236.855" y1="-161.925" x2="247.015" y2="-161.925" width="0.3048" layer="94"/>
<wire x1="236.855" y1="-161.925" x2="205.74" y2="-161.925" width="0.3048" layer="94"/>
<wire x1="205.74" y1="-161.925" x2="205.74" y2="-167.005" width="0.3048" layer="94"/>
<wire x1="205.74" y1="-161.925" x2="205.74" y2="-156.845" width="0.3048" layer="94"/>
<wire x1="205.74" y1="-156.845" x2="247.015" y2="-156.845" width="0.3048" layer="94"/>
<wire x1="205.74" y1="-156.845" x2="205.74" y2="-151.765" width="0.3048" layer="94"/>
<wire x1="205.74" y1="-151.765" x2="247.015" y2="-151.765" width="0.3048" layer="94"/>
<wire x1="205.74" y1="-151.765" x2="205.74" y2="-146.685" width="0.3048" layer="94"/>
<wire x1="247.015" y1="5.715" x2="183.515" y2="5.715" width="0.3048" layer="94"/>
<wire x1="250.19" y1="8.89" x2="183.515" y2="8.89" width="0.3048" layer="94"/>
<wire x1="88.265" y1="-167.005" x2="146.685" y2="-167.005" width="0.3048" layer="94"/>
<wire x1="146.685" y1="-167.005" x2="183.388" y2="-167.005" width="0.3048" layer="94"/>
<wire x1="183.769" y1="-167.005" x2="231.14" y2="-167.005" width="0.3048" layer="94"/>
<wire x1="231.267" y1="-167.005" x2="247.015" y2="-167.005" width="0.3048" layer="94"/>
<wire x1="231.267" y1="-170.18" x2="250.19" y2="-170.18" width="0.3048" layer="94"/>
<text x="14.224" y="-169.926" size="2.1844" layer="94" font="vector">A</text>
<text x="64.262" y="-169.926" size="2.1844" layer="94" font="vector">B</text>
<text x="110.998" y="-169.926" size="2.1844" layer="94" font="vector">C</text>
<text x="159.258" y="-169.926" size="2.1844" layer="94" font="vector">D</text>
<text x="206.756" y="-169.926" size="2.1844" layer="94" font="vector">E</text>
<text x="244.602" y="-169.926" size="2.1844" layer="94" font="vector">F</text>
<text x="247.904" y="-141.478" size="2.1844" layer="94" font="vector">1</text>
<text x="247.65" y="-90.678" size="2.1844" layer="94" font="vector">2</text>
<text x="247.65" y="-39.878" size="2.1844" layer="94" font="vector">3</text>
<text x="205.74" y="6.096" size="2.1844" layer="94" font="vector">E</text>
<text x="157.988" y="6.096" size="2.1844" layer="94" font="vector">D</text>
<text x="110.744" y="6.096" size="2.1844" layer="94" font="vector">C</text>
<text x="62.738" y="6.096" size="2.1844" layer="94" font="vector">B</text>
<text x="14.224" y="6.096" size="2.1844" layer="94" font="vector">A</text>
<text x="-9.398" y="-39.878" size="2.1844" layer="94" font="vector">3</text>
<text x="-9.398" y="-90.932" size="2.1844" layer="94" font="vector">2</text>
<text x="-9.144" y="-143.51" size="2.1844" layer="94" font="vector">1</text>
<text x="207.645" y="-155.575" size="2.1844" layer="94" font="vector">&gt;DRAWING_NAME</text>
<text x="207.645" y="-160.655" size="2.1844" layer="94" font="vector">&gt;LAST_DATE_TIME</text>
<text x="220.98" y="-165.735" size="2.1844" layer="94" font="vector">&gt;SHEET</text>
<text x="207.391" y="-165.862" size="2.1844" layer="94" font="vector">Blatt:</text>
<text x="239.522" y="6.096" size="2.1844" layer="94" font="vector">F</text>
<text x="247.396" y="-2.032" size="2.1844" layer="94" font="vector">4</text>
<text x="-9.652" y="-2.032" size="2.1844" layer="94" font="vector">4</text>
<text x="148.844" y="-161.544" size="5.842" layer="196" font="vector" ratio="14">ICCS SDK</text>
<text x="192.278" y="-161.29" size="3.81" layer="100" font="vector" ratio="14">plus</text>
<text x="207.391" y="-150.622" size="2.1844" layer="94" font="vector">Press F12 to compile</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="CAN_FRAME" prefix="FRAME">
<description>&lt;b&gt;Frame for WE ICCS PLUS&lt;/b&gt;&lt;p&gt;Empty sheet, you can use several frames side by side.</description>
<gates>
<gate name="CAN_FRAME" symbol="FRAME_WE" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="FRAME2" library="CANgraph_EN_WE" deviceset="CAN_FRAME" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="FRAME2" gate="CAN_FRAME" x="-256.54" y="177.8"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
