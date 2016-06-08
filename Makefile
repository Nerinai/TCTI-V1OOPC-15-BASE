.PHONY: clean All

All:
	@echo "----------Building project:[ week_3_oppracht_1 -  ]----------"
	@cd "week_3_oppracht_1" && "$(MAKE)" -f  "week_3_oppracht_1.mk"
clean:
	@echo "----------Cleaning project:[ week_3_oppracht_1 -  ]----------"
	@cd "week_3_oppracht_1" && "$(MAKE)" -f  "week_3_oppracht_1.mk" clean
