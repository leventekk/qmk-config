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


.SILENT: build, clean
build:
	$(call create_docker_tag)

ifeq ($(device), liatris)
	$(call build_firmware,"liatris")
else
	$(call build_firmware,"promicro_rp2040")
endif

clean:
	rm -f firmware/*
