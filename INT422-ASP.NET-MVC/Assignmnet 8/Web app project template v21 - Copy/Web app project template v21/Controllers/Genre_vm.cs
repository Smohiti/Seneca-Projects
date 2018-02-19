using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Web_app_project_template_v21.Controllers
{
    public class Genre_vm
    {
    }
    public class GenreBase
    {
        public int Id { get; set; }

        [Required]
        public string Name { get; set; }
    }
}