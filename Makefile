.PHONY: clean All

All:
	@echo "----------Building project:[ Week_1_opdracht_2 -  ]----------"
	@cd "Week_1_opdracht_2" && "$(MAKE)" -f  "Week_1_opdracht_2.mk"
clean:
	@echo "----------Cleaning project:[ Week_1_opdracht_2 -  ]----------"
	@cd "Week_1_opdracht_2" && "$(MAKE)" -f  "Week_1_opdracht_2.mk" clean
