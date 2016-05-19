.PHONY: clean All

All:
	@echo "----------Building project:[ testing -  ]----------"
	@cd "testing" && "$(MAKE)" -f  "testing.mk"
clean:
	@echo "----------Cleaning project:[ testing -  ]----------"
	@cd "testing" && "$(MAKE)" -f  "testing.mk" clean
