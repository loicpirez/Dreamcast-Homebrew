#include <kos.h>
#include <dc/biosfont.h>
#include <dc/maple.h>
#include <dc/maple/controller.h>

KOS_INIT_FLAGS(INIT_DEFAULT | INIT_MALLOCSTATS);

int	main(void)
{
  maple_device_t *cont1;
  cont_state_t *state;

  cont1 = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

  while (1)
    {
      state = (cont_state_t *)maple_dev_status(cont1);
      if (state->buttons & CONT_START)
	{
	  printf("***Pressed Start***\n");
	  while (state->buttons != 0)
	    {
	      state = (cont_state_t *)maple_dev_status(cont1);
	    }
	  printf("***Release Start***\n");
	}
      if (state->buttons & CONT_B)
	return (1);
    }
}
