DIR          := meta
MODNAME      := meta

META_SRC     := \
		$(DIR)/AnomalousDimension.m \
		$(DIR)/BetaFunction.m \
		$(DIR)/CConversion.m \
		$(DIR)/Constraint.m \
		$(DIR)/FlexibleSUSY.m \
		$(DIR)/LoopMasses.m \
		$(DIR)/Parameters.m \
		$(DIR)/Phases.m \
		$(DIR)/SelfEnergies.m \
		$(DIR)/Tadpoles.m \
		$(DIR)/test_cConversion.m \
		$(DIR)/test_Constraint.m \
		$(DIR)/test_MassEigenstates.m \
		$(DIR)/test_SelfEnergies.m \
		$(DIR)/TestSuite.m \
		$(DIR)/test_textFormatting.m \
		$(DIR)/TextFormatting.m \
		$(DIR)/ThresholdCorrections.m \
		$(DIR)/Traces.m \
		$(DIR)/TreeMasses.m \
		$(DIR)/WriteOut.m

.PHONY:         all-$(MODNAME) clean-$(MODNAME) distclean-$(MODNAME)

all-$(MODNAME):

clean-$(MODNAME):

distclean-$(MODNAME): clean-$(MODNAME)

clean::         clean-$(MODNAME)

distclean::     distclean-$(MODNAME)
