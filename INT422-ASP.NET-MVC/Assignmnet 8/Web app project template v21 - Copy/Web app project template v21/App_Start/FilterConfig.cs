using System.Web;
using System.Web.Mvc;

namespace Web_app_project_template_v21
{
    public class FilterConfig
    {
        public static void RegisterGlobalFilters(GlobalFilterCollection filters)
        {
            filters.Add(new HandleErrorAttribute());
        }
    }
}
