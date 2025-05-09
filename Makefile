DOCKER := "$(shell command -v docker)"
TIMESTAMP := "$(shell date -u +"%Y%m%d%H%M")"

DOCKER_TAG := qmk-builder
KEYMAP_PATH := /app/qmk_firmware/keyboards/crkbd/keymaps/crkbd_custom:ro

define create_docker_tag
	$(DOCKER) build --tag $(DOCKER_TAG) --file Dockerfile .
endef

define build_firmware
	$(DOCKER) run --rm -it --name $(DOCKER_TAG) \
		-v $(PWD)/config:$(KEYMAP_PATH) \
		-v $(PWD)/firmware:/app/firmware \
		-e TIMESTAMP=$(TIMESTAMP) \
		-e KEYMAP_NAME="crkbd_custom" \
		-e DEVICE="$(1)" \
		$(DOCKER_TAG)
endef


.PHONY: help
help:
	@echo "QMK Firmware Builder Help"
	@echo "========================"
	@echo
	@echo "Available commands:"
	@echo
	@echo "  make build              Build firmware for Pro Micro RP2040 (default)"
	@echo "  make build device=liatris Build firmware for Liatris controller"
	@echo "  make clean              Remove all built firmware files"
	@echo
	@echo "Notes:"
	@echo "- Firmware files will be saved in the ./firmware directory"
	@echo "- Keymap configuration is located in ./config"
	@echo "- Timestamp format: YYYYMMDDHHMM (UTC)"
	@echo "- Docker is required to build the firmware"

.SILENT: build clean
build:
	$(call create_docker_tag)

ifeq ($(device), liatris)
	$(call build_firmware,"liatris")
else
	$(call build_firmware,"promicro_rp2040")
endif

clean:
	rm -f firmware/*


