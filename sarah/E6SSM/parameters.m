ParameterDefinitions = {
{g1,           { Description -> "Hypercharge-Coupling"}},
{g2,           { Description -> "Left-Coupling"}},
{g3,           { Description -> "Strong-Coupling"}},
{gN,           { Description -> "Ncharge-Coupling",
                 Dependence -> None,
	         LaTeX -> "g_N",
		 GUTnormalization -> 1/Sqrt[40],
		 LesHouches -> {gauge,4},
	         OutputName -> gN}},
{g1gN,        {Description -> "Mixed Gauge Coupling 1"}},
{gNg1,        {Description -> "Mixed Gauge Coupling 2"}},
{AlphaS,       { Description -> "Alpha Strong"}},
{aEWinv,       { Description -> "inverse weak coupling constant at mZ"}},
{Gf,           { Description -> "Fermi's constant"}},
{e,            { Description -> "electric charge"}},

{Yu,           { Description -> "Up-Yukawa-Coupling",
	         LaTeX -> "Y_u",
		 Form -> Diagonal,
	         Dependence -> None,
	         Value -> None,
		 OutputName -> Yu}},
{Yd,           { Description -> "Down-Yukawa-Coupling",
	         LaTeX -> "Y_d",
		 Form -> Diagonal,
	         Dependence -> None,
	         Value -> None,
		 OutputName -> Yd}},
{Ye,           { Description -> "Lepton-Yukawa-Coupling",
	         LaTeX -> "Y_e",
		 Form -> Diagonal,
	         Dependence -> None,
	         Value -> None,
		 OutputName -> Ye}},

{T[Ye],        { Description -> "Trilinear-Lepton-Coupling",
		 Form -> Diagonal,
	         Dependence -> None,
	         Value -> None}},
{T[Yd],        { Description -> "Trilinear-Down-Coupling",
		 Form -> Diagonal,
	         Dependence -> None,
	         Value -> None}},
{T[Yu],        { Description -> "Trilinear-Up-Coupling",
		 Form -> Diagonal,
	         Dependence -> None,
	         Value -> None}},

{\[Mu],        { Description -> "Mu-parameter",
	       Dependence -> \[Lambda]3*vS/Sqrt[2]}},
{B[\[Mu]],     { Description -> "Bmu-parameter",
	       Dependence -> T[\[Lambda]3]*vS/Sqrt[2]}},

{mq2,          { Description -> "Softbreaking left Squark Mass"}},
{me2,          { Description -> "Softbreaking right Slepton Mass"}},
{ml2,          { Description -> "Softbreaking left Slepton Mass"}},
{mu2,          { Description -> "Softbreaking right Up-Squark Mass"}},
{md2,          { Description -> "Softbreaking right Down-Squark Mass"}},
{mHd2,         { Description -> "Softbreaking Down-Higgs Mass",
                 Dependence -> None,
	         LaTeX -> "m_{h_{13}}^2"}},
{mHu2,         { Description -> "Softbreaking Up-Higgs Mass",
                 Dependence -> None,
	         LaTeX -> "m_{h_{23}}^2"}},
{mHdInert2,    { Description -> "Softbreaking Inert-Down-Higgs Mass",
	         LaTeX -> "m_{h_1}^2",
	         Dependence -> None,
		 LesHouches -> mHdInert2,
	         Value -> None,
		 OutputName -> mHdI}},
{mHuInert2,    { Description -> "Softbreaking Inert-Up-Higgs Mass",
	         LaTeX -> "m_{h_2}^2",
		 Real -> False,
	         Dependence -> None,
		 LesHouches -> mHuInert2,
	         Value -> None,
		 OutputName -> mHuI}},
{mX2,          { Description -> "Softbreaking Exotics Mass",
	         LaTeX -> "m_{X}^2",
		 Real -> False,
                 Dependence -> None,
		 LesHouches -> mX2,
		 OutputName -> mX2}},
{mXBar2,       { Description -> "Softbreaking BarExotics Mass",
	         LaTeX -> "m_{\\bar{X}}^2",
		 Real -> False,
                 Dependence -> None,
		 LesHouches -> mXBar2,
		 OutputName -> mXB2}},
{ms2,          { Description -> "Softbreaking Singlet Mass",
		 Real -> True,
                 Dependence -> None,
		 LesHouches -> {MSOFT,23},
	         LaTeX -> "m_{s_3}^2"}},
{msInert2,     { Description -> "Softbreaking Inert-Singlet Mass",
	         LaTeX -> "m_{s}^2",
		 Real -> False,
		 Form -> Diagonal,
	         Dependence -> None,
		 LesHouches -> msInert2,
		 OutputName -> msI2}},
{mHPrime2,     { Description -> "Softbreaking Survival Mass",
	         LaTeX -> "m_{h'}^2",
	         Real -> False,
		 Form -> Diagonal,
	         Dependence -> None,
		 LesHouches -> {MSOFT,24},
	         Value -> None,
		 OutputName -> mHP2}},
{mHBarPrime2,  { Description -> "Softbreaking Bar-Survival Mass",
	         LaTeX -> "m_{\\bar{h'}}^2",
	         Real -> False,
		 Form -> Diagonal,
	         Dependence -> None,
		 LesHouches ->{MSOFT,25},
	         Value -> None,
		 OutputName -> mHBP2}},

{MassB,        { Description -> "Bino Mass parameter"}},
{MassWB,       { Description -> "Wino Mass parameter"}},
{MassG,        { Description -> "Gluino Mass parameter"}},
{MassU,   { Description -> "Zprimino Mass parameter",
		 LaTeX -> "M_1'",
	         (*Real -> False,*)
	         Form -> Scalar,
		 LesHouches -> {MSOFT,4},
                 (*Dependence -> None,*)
		 OutputName -> M1P}},

{vd,           { Description -> "Down-VEV",
	         LaTeX -> "v_1",
                 Dependence -> None,
	         DependenceOptional -> v Cos[\[Beta]],
                 Value -> None}},
{vu,           { Description -> "Up-VEV",
	         LaTeX -> "v_2",
                 Dependence -> None,
	         DependenceOptional -> v Sin[\[Beta]],
                 Value -> None}},
{v,            { Description -> "EW-VEV"}},
{vS,           { Description -> "Singlet-VEV",
		 Real ->True,
		 Value -> None,
		 LesHouches -> {ESIXRUN,11},
                 Dependence -> None}},

{\[Beta],      { Description -> "Pseudo Scalar mixing angle",
	         DependenceSPheno -> -ArcSin[ZA[1,2]]}},
{\[Phi],       { Description -> "Pseudo Scalar mixing angle phi",
	         LaTeX -> "\\phi",
                 Dependence -> None,
	         DependenceOptional -> ArcTan[TanPhi],
		 Real ->True,
		 LesHouches -> {ESIXRUN, 21},
                 Value -> None,
		 OutputName -> phiH}},
{TanPhi,       { Description -> "Tan Phi",
		 LaTeX -> "\\tan\\phi",
                 Dependence -> None,
		 DependenceOptional -> (v/(2 vS)) Sin[2 \[Beta]],
		 Real ->True,
		 LesHouches -> {ESIXRUN, 22},
                 Value -> None,
		 OutputName -> tPhi}},
{TanBeta,      { Description -> "Tan Beta",
	         LaTeX -> "\\tan\\beta"}},

{ZD,           { Description -> "Down-Squark-Mixing-Matrix" }},
{ZU,           { Description -> "Up-Squark-Mixing-Matrix"}},
{ZE,           { Description -> "Slepton-Mixing-Matrix"}},
{ZV,           { Description -> "Sneutrino Mixing-Matrix"}},

{ZX,           { Description -> "SExotics Mixing-Matrix",
                 LaTeX -> "Z^{x}",
                 Value -> None,
                 Dependence -> None,
		 OutputName -> ZX,
	         LesHouches -> ESIXZX}},

{ZH,           { Description->"Scalar-Mixing-Matrix",
                 LaTeX -> "U_{H}",
                 Real -> False,
		 Dependence -> None,
		 DependenceOptional -> None,
                 Value -> None,
		 LesHouches -> NMHMIX,
		 OutputName -> UH}},
{ZA,           { Description -> "Pseudo-Scalar-Mixing-Matrix",
		 LaTeX -> "U_{A}",
                 Real ->True,
                 DependenceOptional -> {{Cos[\[Beta]],-Sin[\[Beta]],0},
                                        {-Sin[\[Beta]] Sin[\[Phi]],
                                         -Cos[\[Beta]] Sin[\[Phi]],
                                         Cos[\[Phi]]},
                                        {Sin[\[Beta]] Cos[\[Phi]],
                                         Cos[\[Beta]] Cos[\[Phi]],
                                         Sin[\[Phi]]}},
                 Dependence -> None,
                 LesHouches -> NMAMIX}},
{ZP,           { Description -> "Charged-Mixing-Matrix",
	         LaTeX -> "U_{+}",
                 Dependence -> None,
                 DependenceOptional -> {{Cos[\[Beta]],-Sin[\[Beta]]},
					{Sin[\[Beta]],Cos[\[Beta]]}}}},
{ZN,           { Description -> "Neutralino Mixing-Matrix",
                 LesHouches -> NMNMIX}},
{UP,           { Description -> "Chargino-plus Mixing-Matrix"}},
{UM,           { Description -> "Chargino-minus Mixing-Matrix"}},

{UH0Inert,     { Description -> "Inert Neutral Mixing-Matrix",
		 LaTeX -> "U^{h^0}",
		 Value -> None,
		 LesHouches -> INHMIX,
                 Dependence -> None,
		 OutputName -> UHNI}},
{UHpInert,     { Description -> "Inert Charged Mixing-Matrix",
		 LaTeX -> "U^{h^+}",
		 Value -> None,
		 LesHouches -> ICHMIX,
                 Dependence -> None,
		 OutputName -> UHAI}},

{ZSSInert,      { Description -> "Inert Singlet Mixing-Matrix",
		 LaTeX -> "Z^{s_{12}}",
		 Form -> Diagonal,
		 Value -> None,
	         LesHouches -> ZSSI,
                 Dependence -> None,
		 OutputName -> ZSSI}},

{ZNInert,      { Description -> "Inert Neutralino Mixing-Matrix",
		 LaTeX -> "Z^{\\tilde{h}^0}",
		 Value -> None,
	         LesHouches -> ESIXZNI,
                 Dependence -> None,
		 OutputName -> ZNI}},
{ZFSInert,     { Description -> "Inert singlino Mixing-Matrix",
		 LaTeX -> "Z^{\\tilde{s}^0}",
		 Value -> None,
	         LesHouches -> ESIXZSI,
                 Dependence -> None,
		 OutputName -> ZSI}},
{UMInert,      { Description -> "Inert Chargino-minus Mixing-Matrix",
		 LaTeX -> "U^{\\tilde{h}^-}",
		 Value -> None,
	         LesHouches -> ESIXUMI,
                 Dependence -> None,
		 OutputName -> UMI}},
{UPInert,      { Description -> "Inert Chargino-plus Mixing-Matrix",
		 LaTeX -> "U^{\\tilde{h}^+}",
		 Value -> None,
	         LesHouches -> ESIXUPI,
                 Dependence -> None,
		 OutputName -> UPI}},
{ZEL,          { Description -> "Left-Lepton-Mixing-Matrix"}},
{ZER,          { Description -> "Right-Lepton-Mixing-Matrix" }},
{ZDL,          { Description -> "Left-Down-Mixing-Matrix"}},
{ZDR,          { Description -> "Right-Down-Mixing-Matrix"}},
{ZUL,          { Description -> "Left-Up-Mixing-Matrix"}},
{ZUR,          { Description -> "Right-Up-Mixing-Matrix"}},
{ZXL,          { Description -> "Left-Exotic-Mixing-Matrix",
		 OutputName -> ZXL,
	         LesHouches -> ESIXZXL}},
{ZXR,          { Description -> "Right-Exotic-Mixing-Matrix",
		 OutputName -> ZXR,
	         LesHouches -> ESIXZXR}},

{ThetaW,       { Description -> "Weinberg-Angle"}},
{PhaseGlu,     { Description -> "Gluino-Phase" }},

{\[Kappa],     { Description -> "Singlet-Exotic-Interaction",
                 LaTeX -> "\\kappa",
                 Real -> False,
		 Form -> Diagonal,
	         Dependence -> None,
                 Value -> None,
		 OutputName -> kap,
		 LesHouches -> ESIXKAPPA}},
{T[\[Kappa]],  { Description -> "Softbreaking Singlet-Exotic-Interaction",
                 LaTeX -> "T_{\\kappa}",
                 Real -> False,
		 Form -> Diagonal,
	         Dependence -> None,
                 Value -> None,
		 OutputName -> Tkap,
		 LesHouches -> ESIXTKAPPA}},
{\[Lambda],    { Description -> "Singlet-Inert-Higgs-Interaction",
                 LaTeX -> "\\lambda",
                 Real -> False,
		 Form -> Diagonal,
	         Dependence -> None,
                 Value -> None,
		 OutputName -> lam,
		 LesHouches -> ESIXLAMBDA(*,
                 LesHouches -> {NMSSMRUN,1}*)}},
{T[\[Lambda]], { Description -> "Softbreaking Singlet-Inert-Higgs-Interaction",
                 LaTeX -> "T_{\\lambda}",
                 Real -> False,
		 Form -> Diagonal,
                 Dependence -> None,
                 Value -> None,
		 OutputName -> Tlam,
		 LesHouches -> ESIXTLAMBDA(*,
                 LesHouches ->{NMSSMRUN,3}*)}},
{\[Lambda]3,   { Description -> "Singlet-Higgs-Interaction",
	         LaTeX -> "\\lambda_3",
                 Real -> False,
                 Dependence -> None,
		 Form -> Scalar,
		 OutputName -> lam3,
		 LesHouches ->  {ESIXRUN,1}}},
{T[\[Lambda]3],{ Description -> "Softbreaking Singlet-Higgs-Interaction",
	         LaTeX -> "T_{\\lambda_3}",
                 Real -> False,
                 Dependence -> None,
		 Form -> Scalar,
		 OutputName -> Tlam3,
		 LesHouches ->  {ESIXRUN,2}}},

(*added for HiggsPrime*)
{muPrime,      { Description -> "MuPrime-parameter",
		 Form -> Scalar,
                 Dependence -> None,
		 LesHouches -> {ESIXRUN,0},
		 LaTeX -> "\\mu'",
		 OutputName -> muP}},
{B[muPrime],   { Description -> "BMuPrime-parameter",
		 Form -> Scalar,
                 Dependence -> None,
		 LesHouches -> {ESIXRUN,101},
		 LaTeX -> "B_{\\mu'}",
		 OutputName -> BmuP}},
{UH0Prime,     { Description -> "Prime neutral mixing matrix",
                 Dependence -> None,
		 LesHouches -> UHNPMIX,
		 OutputName -> UHNP}},
{UHpPrime,     { Description -> "Prime charged mixing matrix",
                 Dependence -> None,
		 LesHouches -> UHPPMIX,
		 OutputName -> UHAP}},
{ZNPrime,      { Description -> "Prime Neutralino mixing matrix",
                 Dependence -> None,
		 LesHouches -> ZNPMIX,
		 OutputName -> ZNP}},

(*EWSB mixing matrices*)
{ThetaWp,  { Description -> "Theta'",
	     LesHouches -> {ESIXRUN,20},
	     DependenceNum -> 1/2 ArcTan[Sqrt[g1^2+g2^2] gN (-3 vd^2 + 2 vu^2)
	       /(gN^2 (9 vd^2 + 4 vu^2 + 25 vS^2 )-(g1^2+g2^2) (vd^2 + vu^2)/4)]
	     (* DependenceNum -> None *)  }},
(*Mixing angle of Z' and Z*)
{ZZ, {Description ->   "Photon-Z-Z' Mixing Matrix"}},
{ZW, {Description -> "W Mixing Matrix" }},
{ZfW, {Description ->    "Wino Mixing Matrix"}}
};
