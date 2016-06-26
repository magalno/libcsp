/*
 * csp_nuts.c
 *
 * Created: 18.03.2016 18:56:12
 *  Author: Normann
 */ 

#include "csp/csp.h"
#include "csp/csp_nuts.h"
#include "config/conf_csp.h"

uint8_t csp_nuts_init(void){
		/* Init buffer system with 10 packets of maximum 300 bytes each */
	printf("Initialising CSP\r\n");
	csp_buffer_init(10, 300);
	
	/* Init CSP with address MY_ADDR */
	csp_init(MY_ADDR);

	/* Start router task with 1000 word stack, OS task priority 1 */
	csp_route_start_task(1000, 1);

	/* Enable debug output from CSP */
	printf("Debug enabed\r\n");
	//csp_debug_toggle_level(CSP_BUFFER);
	//csp_debug_toggle_level(CSP_PACKET);
	//csp_debug_toggle_level(CSP_PROTOCOL);

	printf("Conn table\r\n");
	csp_conn_print_table();

	printf("Route table\r\n");
	csp_route_print_table();

	printf("Interfaces\r\n");
	csp_route_print_interfaces();
}