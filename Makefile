.PHONY: clean All

All:
	@echo "----------Building project:[ week_3_oppracht_3 -  ]----------"
	@cd "week_3_oppracht_3" && "$(MAKE)" -f  "week_3_oppracht_3.mk"
clean:
	@echo "----------Cleaning project:[ week_3_oppracht_3 -  ]----------"
	@cd "week_3_oppracht_3" && "$(MAKE)" -f  "week_3_oppracht_3.mk" clean
